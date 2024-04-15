#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
// The purpose of this file is to create a game object
// that would represent game objects in our game

// =========== Third Party Libraries ===========
// Include our pybind11 library
#include <pybind11/pybind11.h>
// Also need to include the embedded interpreter
// for our 'ExecuteScript' command
#include <pybind11/embed.h>

// Setup the namespace
namespace py = pybind11;

#include <string>

typedef unsigned int uint;

struct ScriptComponent{
    void Run(){
        py::exec("print('"+mScript+".run()')");
        py::exec(mScript+".run()");
    }
    void LoadScript(const std::string filename){
          mScript = filename;
          py::exec("print('Loading script:"+mScript+"')");
          py::exec("import "+mScript);
    }

    std::string mScript;
};

// Create a new Game Object
struct GameObject{
public:
    /// Default Constructor
    GameObject();
    /// On argument Constructor with name
    GameObject(const std::string &name);
    // Setter
    void SetName(const std::string &name_);
    // Getter
    const std::string &GetName() const;

    void Input(){}
    void Update(){
        mScript.Run();
    }
    void Render(){}

    // Every Game Object has a 'Script Component' for now
    ScriptComponent mScript;
    uint mID;
private:
    // Name of our game object
    std::string name;
    // Keep track of how many game objects
    // we have.
    static unsigned int m_uniqid;
};


#endif
