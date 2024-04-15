#pragma once 
#include <iostream>
#include <vector>
#include <string>

#include "GameObject.hpp"

/// Game app
struct GameApp{
    /// Default constructor
    GameApp();

    /// Setup the game objects for our system
    void StartUp(const std::string filename);

    void ShutDown();

    // For demonstration purposes we are creating a factory
    // so that objects can be created and owned in C++  
    void CreateGameObject(const std::string name, const std::string scriptfilename);

    void Input();

    void Update();

    void Render();

    void Loop();

    /// Data
    // Note: Ideally this is populated as a 'scene' and
    //       loaded from some configuration file.
    std::vector<GameObject> gameObjects;
};

