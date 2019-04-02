# shake3

Shake is a hobby game engine / programming sandbox.    
It is implemented using C++ and supports Python scripting.

It's most interesting features are currently:

* clearly separated submodules, so that parts of the engine could be used as standalones.    
* An easy to use API for graphics using OpenGL. 
* An entity-component-systems architecture for flexibility and scalability in creating game worlds.
* A Python interface (pyshake) using Pybind11, that allows for interesting interoperability.    
I.e. Python objects can inherit from C++ objects, allowing the engine the manage Python-based systems in C++ )

Shake is still under active development.    
Demo's will hopefully follow soon.     

This repository simply includes all submodules and combines them into a single project.    
Please check out the submodules as well:    

* [shake_content](https://github.com/berryvansomeren/shake_content/)
* [shake_core](https://github.com/berryvansomeren/shake_core/)
* [shake_ecs](https://github.com/berryvansomeren/shake_ecs/)
* [shake_graphics](https://github.com/berryvansomeren/shake_graphics/)
* [shake_hid](https://github.com/berryvansomeren/shake_hid/)
* [shake_io](https://github.com/berryvansomeren/shake_io/)
* [shake_main](https://github.com/berryvansomeren/shake_main/)
* [shake_python](https://github.com/berryvansomeren/shake_python/)
* [shake_test_game](https://github.com/berryvansomeren/shake_test_game/)
