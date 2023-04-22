#include <pybind11/pybind11.h>
#include "math_lib.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
    m.doc() = R"Pybind11 example plugin";

    m.def("add", &add, "Add two numbers");

    m.def("subtract", [](int i, int j) { return i - j; }, "Subtract two numbers");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "0.0.1";
#endif
}
