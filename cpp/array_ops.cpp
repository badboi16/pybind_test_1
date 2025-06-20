#include "array_ops.h"
#include <stdio.h>

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

void add_2D_array(py::array_t<double> input) {

	auto buf = input.request();
	double* ptr = static_cast<double*>(buf.ptr);
	size_t n = buf.size;

	printf("Size of 2D array passed: %lf\n", double(n));

	// Let's check dimensions of the array passed to this function
	size_t rows = buf.shape[0]; // eg. bars in data, matching vector indices
	size_t cols = buf.shape[1];
	printf("Dimensions of array passed: %lf x %lf\n", double(rows), double(cols));

	// Let's initialize new array of the same size
	py::array_t<double> new_array({ rows, cols });

	// When you get buf.ptr or use unchecked<N>(), you are operating directly on
	// the memory owned by the Python NumPy array. This means there's no overhead
	// of copying large datasets between Python and C++ memory spaces.

	// Let's get the new array's buf_info and ptr
	auto new_buf = new_array.request();
	double* new_ptr = static_cast<double*>(new_buf.ptr);

	for (size_t i = 0; i < rows; ++i) {
		printf("\n");
		for (size_t j = 0; j < cols; ++j) {
			printf("%lf --- ", double(ptr[i * cols + j]));
			// assign to new array 2x the values in passed array
			new_ptr[i * cols + j] = 2 * ptr[i * cols + j];
		}
	}
	printf("\nNow printing new 2x array...");
	for (size_t i = 0; i < rows; ++i) {
	printf("\n");
		for (size_t j = 0; j < cols; ++j) {
			printf("%lf --- ", double(new_ptr[i * cols + j]));
		}
	}
}