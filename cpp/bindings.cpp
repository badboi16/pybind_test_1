#include <pybind11/pybind11.h>
#include <iostream>
#include <stdio.h>

int add(int a, int b) {
    std::cout << "cpp: Adding..." << std::endl;
    return a + b;
}

int subtract(int a, int b) {
    std::cout << "cpp: Subtracting..." << std::endl;
    return a - b;
}

PYBIND11_MODULE(example, m) {
    m.def("add", &add, "Add two numbers");
    m.def("subtract", &subtract, "Subtract two numbers");

}
