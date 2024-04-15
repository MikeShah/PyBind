// Include library that allows embedding of pybind
// into the engine
#include <pybind11/embed.h>
namespace py = pybind11; // shorten what we need to type

#include <vector>

#include "./engine/GameApp.hpp"
#include "./engine/GameObject.hpp"

int main(int argc, char* argv[]){
    // Starts the python interpreter and keeps it alive
    // The interpreter must be created before we can use
    // any of our Python functions.
    py::scoped_interpreter guard{};

    // By default, we need to import our engine so that we
    // can take advantage of the functions used in any
    // scripting capability
    py::exec("import myengine");
    
    // Assume that 'scene1.txt' is the starting scene.
    // Could otherwise pass this in through command line
    // arguments. A game executable 'shortcut' would then
    // always load the correct scene.
    // Note: In practice, you might embed the scene1.txt into
    //       the executable to avoid hackers from jumping
    //       to scenes ahead of time.
    // Note: One other strategy, is to just simply use python
    //       to configure and setup your levels.
    //       I have done that here for simplicity, though in
    //       practice you  might have some other 'scene' format
    //       that you can compress, and load up in parallel
    //       using your engine to initialize memory and
    //       setup everything through a resource manager.
    GameApp scene1;
    scene1.StartUp("level1.py");

    return 0;
}
