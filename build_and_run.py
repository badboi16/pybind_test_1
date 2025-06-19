import subprocess
import os
import sys

# Paths
BUILD_DIR = "build"
CPP_DIR = "cpp"
CONFIG = "Release"
PYD_NAME = "example.pyd"
TEST_SCRIPT = "test_example.py"

# Step 1: Run CMake to regenerate build files (only needed if CMakeLists.txt changed)
def run_cmake():
    print("🔧 Running cmake...")
    subprocess.run(["cmake", f"../{CPP_DIR}"], cwd=BUILD_DIR, check=True)

# Step 2: Build the C++ extension
def build():
    print("🛠️  Building...")
    subprocess.run(["cmake", "--build", ".", "--config", CONFIG], cwd=BUILD_DIR, check=True)

# Step 3: Run the test script
def test():
    print("🧪 Running test...")
    subprocess.run([sys.executable, TEST_SCRIPT], check=True)

# Main logic
if __name__ == "__main__":
    if not os.path.isdir(BUILD_DIR):
        os.mkdir(BUILD_DIR)
        run_cmake()
    build()
    test()
