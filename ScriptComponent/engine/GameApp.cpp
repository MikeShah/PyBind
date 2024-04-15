#include "GameApp.hpp"
#include <fstream>
#include <string>

GameApp::GameApp(){

}

/// Setup the game objects for our system
void GameApp::StartUp(const std::string filename){ 
    std::ifstream script(filename);
    std::string line;
    if(script.is_open()){
        // Read each line at a time and execute
        while(std::getline(script,line)){
            py::exec(line.c_str());
        } 
        script.close();
    }
}

void GameApp::ShutDown(){
}

void GameApp::CreateGameObject(const std::string name, const std::string scriptfilename){
    GameObject go(name);
    // Load the script for the game object
    go.mScript.LoadScript(scriptfilename);
    // Assume ownership on the C++ vector collection
    gameObjects.push_back(go);
}

void GameApp::Input(){
    for(auto& go : gameObjects){
        go.Input();
    }
}

void GameApp::Update(){
    for(auto& go : gameObjects){
        go.Update();
    }
}

void GameApp::Render(){
    for(auto& go : gameObjects){
        go.Render();
    }
}

void GameApp::Loop(){
    // For demonstration purposes, the game loop 
    // only runs a finite number of times.
    size_t i=0;
    while(i < 5){
        std::cout << "===== Simulating game loop frame " << i << " =====" << std::endl;
        Input();
        Update();
        Render();
        i++;
    }
}

