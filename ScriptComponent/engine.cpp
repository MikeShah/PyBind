// Include library that allows embedding of pybind
// into the engine
#include <pybind11/embed.h>
namespace py = pybind11; // shorten what we need to type

#include <iostream>
#include <vector>
#include <string>

typedef unsigned int uint;

struct ScriptComponent{
    void Run(){
        py::exec("mario = mymodule.GameObject('luigi')");
        py::exec("mario.SetName('Mario')");
        py::exec("mario.ExecuteScript('mario.py')");
    }
    void LoadScript(std::string filename){
        mScript = filename;
    }

    std::string mScript;
};

struct GameObject{

    void Input(){}
    void Update(){
        mScript.Run();
    }
    void Render(){}

    ScriptComponent mScript;
    uint mID;
};

struct Globals{
    std::vector<GameObject> gameObjects;
};

/// One global game object
Globals g;


/// Game app
struct Game{
    /// Setup the game objects for our system
    void StartUp(std::string filename){ 

        GameObject go;
        g.gameObjects.push_back(go);
    }
    void ShutDown(){
    }

    void Input(){
        for(auto& go : g.gameObjects){
            go.Input();
        }
    }

    void Update(){
        // After doing this, we can now execute python
        // through our interpeter that is making
        // module calls.
        py::exec("print('Engine is starting')");
        py::exec("import mymodule");

        for(auto& go : g.gameObjects){
            go.Update();
        }
    }

    void Render(){
        for(auto& go : g.gameObjects){
            go.Render();
        }
    }

    void Loop(){
        
        size_t i=0;
        while(i < 10){
            std::cout << "===== Simulating game loop frame " << i << " =====" << std::endl;
            Input();
            Update();
            Render();
            i++;
        }
    }
};

int main(){
    // Starts the python interpreter and keeps it alive
    // The interpreter must be created before we can use
    // any of our Python functions.
    py::scoped_interpreter guard{};
    
    Game level1;
    level1.StartUp("scene1.txt");
    level1.Loop();
    

    return 0;
}
