cmake_minimum_required(VERSION 3.15)
project(example)

# Step 1: Find Python
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Step 2: Include pybind11 headers manually (since you're using pip-installed pybind11)
include_directories(
    "${Python3_INCLUDE_DIRS}"
    "C:/Users/Nihhit/projects/pybind_test_1/pybind_test_1_env/Lib/site-packages/pybind11/include"
)

# Step 3: Tell the linker where python313.lib is
link_directories("C:/Users/Nihhit/AppData/Local/Programs/Python/Python313/libs")

# Step 4: Define the library to build
add_library(example MODULE bindings.cpp)

# Step 5: Link against the Python lib (important: after add_library)
target_link_libraries(example PRIVATE python313)

# Step 6: Make sure the output file is a Python extension
set_target_properties(example PROPERTIES PREFIX "" SUFFIX ".pyd")
