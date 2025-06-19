Only python installed globally, all modules such as Pybind11 in specefic environments only 

No seperate CMake installation needed, simply select C++ Desktop Development while installing MSVC

I used x64 Native Tools Command Prompt for VS 2022 in Admin mode


While installing python,
- selected Download debugging symbols
- selected Download debug binaries 
These options will install the missing python313.lib and other development files needed for linking from C++



My final CMakeLists.txt ------
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
----------------------------------




from build I ran
-> cmake ..\cpp
-> cmake --build . --config Release




pythonlib313 found at "C:/Users/Nihhit/projects/pybind_test_1/pybind_test_1_env/Lib/site-packages/pybind11/include"




After any changes I make to the cpp file, I need to run ||->cmake --build . --config Release|| inside the build folder