# Why am I not using Make?
# 1.)   I want total control over the system.
#       Occassionally I want to have some logic
#       in my compilation process.
# 2.)   Realistically our projects are 'small' enough
#       this will not matter.
# 3.)   Feel free to implement your own make files.
# 4.)   It is handy to know Python


import os

COMPILER="g++"

SOURCE="./src/*.cpp"

# You can can add other arguments as you see fit.
# What does the "-D LINUX" command do?
ARGUMENTS="-D LINUX -std=c++14 -shared -fPIC"

# Which directories do we want to include.
INCLUDE_DIR="-I ./include/ -I./pybind11/include/ `python3.5 -m pybind11 --includes`"

# What libraries do we want to include
LIBRARIES="-lSDL2 -ldl `python3.5-config --ldflags`"

# The name of our module
EXECUTABLE="mygameengine.so"

# Build a string of our compile commands that we run in the terminal
compileString=COMPILER+" "+ARGUMENTS+" -o "+EXECUTABLE+" "+" "+INCLUDE_DIR+" "+SOURCE+" "+LIBRARIES

# Print out the compile string
print(compileString)

# Run our command
os.system(compileString)
