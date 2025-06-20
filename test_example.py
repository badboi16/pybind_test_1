import sys
import os
import numpy as np

# Add the path to the compiled module
sys.path.append(os.path.join(os.path.dirname(__file__), 'build', 'Release'))

import example

print("Calling C++ function from Python...")
result = example.add(10, 20)  # Use your actual function name
print("Result:", result)
result = example.subtract(10, 20)  # Use your actual function name
print("Result:", result)

# Calling cpp function on 1D array
arr = np.array([1.0, 2.0, 3.0])
result = example.double_array(arr)
print("Input:", arr)
print("Result:", result)

# Lets call cpp function on a 2D array
# This function takes in ndarray and simply prints 2x each element
arr_2d = np.array([[1, 2, 3],
                   [4, 5, 6]])
example.add_2D_array(arr_2d) 