#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
// The purpose of this file is to create a game object
// that would represent game objects in our game

#include <string>

// Create a new Game Object
class GameObject{
public:
    // Constructor
    GameObject(const std::string &name);
    // Setter
    void SetName(const std::string &name_);
    // Getter
    const std::string &GetName() const;
    // This function will load a script file
    // that is written in python and evaluate it.
    // We are going to use it to load some of
    // the functions in this library
    void ExecuteScript(std::string pythonScriptFile); 
private:
    // Name of our game object
    std::string name;
    // Keep track of how many game objects
    // we have.
    static unsigned int m_uniqid;
};


#endif
