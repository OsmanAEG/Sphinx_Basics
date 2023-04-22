import sys
sys.path.insert(1, '../build')

import cmake_example

x = cmake_example.add(1, 2)

print(x)