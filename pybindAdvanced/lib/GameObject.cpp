#include "GameObject.hpp"

// ========= C++ Standard Libraries ============
#include <iostream>
#include <string>
#include <fstream>

// =========== Third Party Libraries ===========
// Include our pybind11 library
#include <pybind11/pybind11.h>
// Also need to include the embedded interpreter
// for our 'ExecuteScript' command
#include <pybind11/embed.h>

// Setup the namespace
namespace py = pybind11;


// Create a new Game Object
GameObject::GameObject(const std::string &name) : name(name){
    m_uniqid++;
}

// Setter
void GameObject::SetName(const std::string &name_){
    name = name_;
}
// Getter
const std::string& GameObject::GetName() const { return name; }

// This function will load a script file
// that is written in python and evaluate it.
// We are going to use it to load some of
// the functions in this library
void GameObject::ExecuteScript(std::string pythonScriptFile){
    std::ifstream script(pythonScriptFile);
    std::string line;
    if(script.is_open()){
        // Read each line at a time and execute
        while(std::getline(script,line)){
            py::exec(line.c_str());
        } 
        script.close();
    }
}    

// Setup any static variables
unsigned int GameObject::m_uniqid = 0;

// Creates a macro function that will be called
// whenever the module is imported into python
// 'mymodule' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(mymodule, m){
    m.doc() = "example plugin"; // Optional docstring

    py::class_<GameObject>(m, "GameObject")
            .def(py::init<const std::string &>())   // our constructor
            .def("SetName", &GameObject::SetName)   // Expose member methods
            .def("GetName", &GameObject::GetName)   
            .def("ExecuteScript", &GameObject::ExecuteScript); 
//          .def_readwrite("name",&GameObject::name);  // Expose member variables
}
