#include "GameObject.hpp"

// ========= C++ Standard Libraries ============
#include <iostream>
#include <string>
#include <fstream>

/// Default Constructor
GameObject::GameObject(){
}

// Create a new Game Object
GameObject::GameObject(const std::string &name) : name(name){
    m_uniqid++;
}

// Setter
void GameObject::SetName(const std::string &name_){
    name = name_;
}
// Getter
const std::string& GameObject::GetName() const { 
    return name; 
}

// Setup any static variables
unsigned int GameObject::m_uniqid = 0;

