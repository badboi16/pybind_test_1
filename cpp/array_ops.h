#pragma once

#include <pybind11/numpy.h>

// Declare the function
pybind11::array_t<double> double_array(pybind11::array_t<double> input);
