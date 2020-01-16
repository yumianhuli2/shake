# shake3

Shake is a hobby game engine / programming sandbox.    
It is implemented using a C++ core with Python bindings.

It's most interesting features are currently:
   
* An easy to use graphics API using the latest version of OpenGL (4.6) and it's DSA features. 
* An entity-component-systems architecture for flexibility, scalability and performance in managing game worlds.
* Python bindings (pyshake) created using Pybind11, that enable you to easily script your own games.
* Uses CMake for build management, but actually uses Python for target specification. 
* Uses modern c++(17) features such as any, variant, visit and fold expressions.
* Uses custom (pre-c++20) ranges inspired by Python ranges and Boost Range.

Shake is only in it's initial stage and is still undergoing active development, and massive refactoring efforts.   
A first demo will hopefully follow soon.     

This repository simply includes all submodules and combines them into a single project.    
The submodules are:  

* [shake_content](https://github.com/berryvansomeren/shake_content/)
* [shake_core](https://github.com/berryvansomeren/shake_core/)
* [shake_ecs](https://github.com/berryvansomeren/shake_ecs/)
* [shake_graphics](https://github.com/berryvansomeren/shake_graphics/)
* [shake_hid](https://github.com/berryvansomeren/shake_hid/)
* [shake_io](https://github.com/berryvansomeren/shake_io/)
* [shake_main](https://github.com/berryvansomeren/shake_main/)
* [shake_python](https://github.com/berryvansomeren/shake_python/)
* [shake_test_game](https://github.com/berryvansomeren/shake_test_game/)
