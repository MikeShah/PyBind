#include "GameObject.hpp"
#include "GameApp.hpp"

// Creates a macro function that will be called
// whenever the module is imported into python
// 'myengine' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(myengine, m){
    m.doc() = "example plugin"; // Optional docstring

    /// Game Object Bindings ///
    py::class_<GameObject>(m, "GameObject")
            .def(py::init<const std::string &>())   // our constructor
            .def("SetName", &GameObject::SetName)   // Expose member methods
            .def("GetName", &GameObject::GetName)   
            ; 
//          .def_readwrite("name",&GameObject::name);  // Expose member variables

    py::class_<ScriptComponent>(m, "ScriptComponent")
            .def("Run",&ScriptComponent::Run)
            .def("LoadScript",&ScriptComponent::LoadScript);

    /// Game Bindings ///
    py::class_<GameApp>(m, "GameApp")
            .def(py::init<>())   // our constructor
            .def("StartUp", &GameApp::StartUp)   // Expose member methods
            .def("CreateGameObject", &GameApp::CreateGameObject)   // Expose member methods
            .def("Loop", &GameApp::Loop);        // Expose member methods
}
