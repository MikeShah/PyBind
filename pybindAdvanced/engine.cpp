// Include library that allows embedding of pybind
// into the engine
#include <pybind11/embed.h>
namespace py = pybind11; // shorten what we need to type




int main(){
    // Starts the python interpreter and keeps it alive
    // The interpreter must be created before we can use
    // any of our Python functions.
    py::scoped_interpreter guard{};

    
    // After doing this, we can now execute python
    // through our interpeter that is making
    // module calls.
    
    py::exec("print('Engine is starting')");
    py::exec("import mymodule");

    py::exec("mario = mymodule.GameObject('luigi')");
    py::exec("mario.SetName('Mario')");
    py::exec("mario.ExecuteScript('mario.py')");


    return 0;
}
