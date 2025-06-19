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

arr = np.array([1.0, 2.0, 3.0])
result = example.double_array(arr)
print("Input:", arr)
print("Result:", result)