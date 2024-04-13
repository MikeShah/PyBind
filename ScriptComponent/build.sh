# build the library first in the ./lib folder
clang++ -shared -fPIC -std=c++17 -I./pybind11/include/ `python3.6 -m pybind11 --includes` ./lib/*.cpp -o mymodule.so `python3.6-config --ldflags`

# Then build our engine executable
clang++ -std=c++17 `python3.6 -m pybind11 --includes` engine.cpp -o engine `python3.6-config --ldflags`
