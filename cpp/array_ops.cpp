#include "array_ops.h"

namespace py = pybind11;

// Library - Specific Type : 
// Many libraries or frameworks define their own types to represent 
// arrays or collections of data.For instance, in 
// pybind11(a library for interoperability between C++ and Python), 
// you'll find pybind11::array_t. This array_t is a template class 
// specifically designed to work with NumPy arrays in Python, 
// allowing you to pass data efficiently between C++ and Python.

py::array_t<double> double_array(py::array_t<double> input) {
	
	auto buf = input.request(); // returns an array::buffer_info
	// object contains low-level details about the NumPy array's
	// memory layout, such as a pointer to the raw data, the 
	// data type, the dimensions, and the strides.
	
	double* ptr = static_cast<double*>(buf.ptr); // use static_cast 
	// to explicitly cast this void* pointer to a double*

	size_t n = buf.size; //holds the total number of elements in 
	// the NumPy array (e.g., for a 2x3 array, size would be 6)

	py::array_t<double> result(n); // construct new 1D array of n
	// elements initialized with doubles (likely 0s ?, pybind 
	// version dependent)

	auto result_buf = result.request(); // fetching buffer_info 
	// for new array, result_buf now holds the low-level memory
	// information for our new result array

	double* result_ptr = static_cast<double*>(result_buf.ptr);
	// cast the void* pointer from result_buf.ptr to a double* 
	// so we can write double values into this memory region
	// Result_ptr is now a raw C++ pointer to the memory where 
	// the output NumPy array's data will be stored

	for (size_t i = 0; i < n; ++i) {
		result_ptr[i] = 2 * ptr[i];
	} // multiplying the contents of input vector by 2 and 
	// storing in new vector

	return result;

}