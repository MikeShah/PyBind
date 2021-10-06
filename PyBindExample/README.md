**You may work with your Assignment 2 Teams on this lab**

- [ ] **Check this box (edit this README.md and put an 'x' between the brackets to check the box) if you worked with your A2 teammates on this and we'll take the top score**

# Lab 7 - Scripting

<img align="right" width="200px" src="./media/lab.jpg">

> Scripting! $1,000,000

**Lab materials must be pushed to your repository one week from now before the next class begins**

**Read:** *Labs are designed to be finished in class if you work diligently, but expected to take 1-2 hours outside of class. They are often more 'tutorial' in style, and sometimes the solution may even be provided in pieces for you to type in and experiment. Copying & Pasting is discouraged however--make mistakes, play, and you will further learn the material.*

## Modify this section

- How many hours did it take you to complete this lab?
- Did you collaborate with any other students/TAs/Professors?
- Did you use any external resources? (Cite them below)
  - tbd
  - tbd
- (Optional) What was your favorite part of the lab?
- (Optional) How would you improve the lab?

## Logistics

You will be working on your own laptop today.

# Introduction

Today's class is a work day in a sense. You are going to work on building a library of code that can be used in the Python 3+ programming language. This can vary from very difficult to simple for the setup. In fact, I have provided a large part of code as a sample, but I would like you to be creative in adapting and adding to it. By the end of this lab, you will have enough to script a subset of a pong game in the Python langauge which is using your C++ code as a library to perform 3D graphics. 

The immediate difficulty will be in getting things setup! Be forewarned! Reading documentation is key https://pybind11.readthedocs.io/en/stable/

# Part 1 - Try compiling the sample

Provided in the root directory is a sample [pybind.cpp](./pybind.cpp). Within the source file are directions on how to build the sample for your respective operating system. For example, on Ubuntu run:

Note: Some folks may have python3.6 or python3.7 and need to change flags appropraitely to match the version on their system.

```
clang++ -shared -fPIC -std=c++11 -I./pybind11/include/ `python3.5 -m pybind11 --includes` pybind.cpp -o mymodule.so `python3.5-config --ldflags`
```

After building successfully, you will have a *mymodule* library that you can import into python3.X (where 'X' is your version of python). See the bottom as an example.

```python
$ python3
>>> import mymodule
>>> help(mymodule)
Help on module mymodule:

NAME
    mymodule - example plugin

CLASSES
    pybind11_builtins.pybind11_object(builtins.object)
        Pet

    class Pet(pybind11_builtins.pybind11_object)
     |  Method resolution order:
     |      Pet
     |      pybind11_builtins.pybind11_object
     |      builtins.object
     |
     |  Methods defined here:
     |
     |  __init__(...)
     |      __init__(self: mymodule.Pet, arg0: str) -> None
     |
     |  getName(...)
     |      getName(self: mymodule.Pet) -> str
     |
     |  setName(...)
     |      setName(self: mymodule.Pet, arg0: str) -> None

```

Here is an example of actually using our module. Again, this is your C/C++ engine running as a library within in Python3.X.

```python
>>> import mymodule
>>> mymodule.add(1,2)
3
```

Another example, this time using classes!

```python
>>> import mymodule
>>> p = mymodule.Pet('moe')
>>> print(p)
<mymodule.Pet object at 0x000000000319c650>
>>> p.getName()
'moe'
>>> p.setName('test')
>>> p.getName()
'test'
```

# Part 2 - Pong (EngineLibrary Folder)

<img align="right" width="400px" src="./media/pong.gif">

Navigate to the [./EngineLibrary](./EngineLibrary) directory. Once again, build the engine library and make sure pybind is working. Your deliverable, will be to implement a pong game in a Python script using the pybind interface to your C++ code. The pong game itself can be very simple (no need to have fancy menus, just two paddles that can bounce a ball back and forth)

### Compiling and running the support code

* (See directions in the [./EngineLibrary](./EngineLibrary) folder)
  
## Helpful Resources

Some additional resources to help you through this lab assignment

- [Embedding Python in the Ogre3D engine](https://www.youtube.com/watch?v=P9edayG8rkg)
- [Extending Python With C Or C++ With Pybind11](https://blog.conan.io/2016/04/12/Extending-python-with-C-or-C++-with-pybind11.html)

## Deliverables

- Implement pong in a Python script using the pybind interface to your C++ code.

You must complete this lab one week from today's class. <!-- You will run your lab in front of me at the start of the next lab when class starts and tell me what your group # was for that week. -->

## Rubric

You (and any partner(s)) will receive the same grade from a scale of 0-2.

- 0 for no work completed by the deadline
- 1 for some work completed, but something is not working properly
- 2 for a completed lab (with possible 'going further' options completed)

## Going Further

What is that, you finished Early? Did you enjoy this lab? Here are some (optional) ways to further this assignment.

- You can implement your platformer in Python if you build your game engine as a library
- Read more on Pybind11
- Watch a lua tutorial and try to implement lua.h and support two programming langauges!


## Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

- Fun fact: The famous computer scientist Donald Knuth would pay folks one $2.56 for errors in his published works. [[source](https://en.wikipedia.org/wiki/Knuth_reward_check)]
- Unfortunately, there is no monetary reward in this course :)
