# build the library first in the ./engine folder
clang++ -shared -fPIC -std=c++17 -I./pybind11/include/ `python3.6 -m pybind11 --includes` ./engine/*.cpp -o myengine.so `python3.6-config --ldflags`

# Then build our game exeucutabel along with any
# dependencies from our engine (i.e. all of ./engine/*.cpp)
clang++ -std=c++17 `python3.6 -m pybind11 --includes` engine_start.cpp ./engine/*.cpp -o engine_start `python3.6-config --ldflags`
