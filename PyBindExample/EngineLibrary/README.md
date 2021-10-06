# Bare Minimum Instructions

1. Run the appropriate build script for your operating system:
    - Mac: `python macbuild.py`
    - Linux: `python linuxbuild.py`
    - Windows `sh mingw64build.sh`
    - If the script works properly, it will generate `mygameengine.pyd` on Windows or a  `mygameengine.so` file on linux & mac.
        - If the script does not work properly, you may need to do a little bit of searching to figure out how to setup pybind. I have given you a headstart to setup pybind, and *it may just work* on some platforms and not so easily for others using different development stacks.
2. Then run the [test.py](./test.py) which uses your engine.
    - Windows: `python3.6 test.py -m ./mygameengine.pyd` (Note: We are using Python3)
    - Linux and Mac: `python3.5 test.py -m ./mygameengine.so` (Note: We are using Python3)


# Common Errors with pybind11 setup

- If you get a missing “python.h” error message, then you likely do not have python3-dev (or python2-dev installed).
    - Make sure to install the python development version and associated libraries.
    - (`sudo apt-get install python3-dev` for linux)
    - (`brew install python3-dev` for mac or https://stackoverflow.com/questions/41743825/how-to-install-python3-4-dev-for-mac)
        - brew update ; brew install pyenv ; pyenv install 3.5.0 ; pyenv install 3.5-dev
    - For MinGW users
        - pacman -S mingw-w64-x86_64-python3-pip
        - pip3 install pybind11
- If you get a ‘module pybind11’ not found, then you need to do the
    - pip3 install pybind11 (If you are using python 3)
    - or
    - pip install pybind11
- Finally, check the build scripts to see if the correct version of python is being used (3, 3.5, 3.6, etc.)

