# shake

Shake is a hobby game engine / programming sandbox.    
It is implemented using a C++ core with Python bindings for scripting.
Because the project grew too time-consuming I've abondoned it.
It was never really completed as a game engine but from time to time I revisit it to do some sandbox programming.

Some of the more interesting features I was working on/exploring are:
   
* An easy to use graphics API using OpenGL (4.6) and it's DSA features. 
* An entity-component-systems architecture for flexibility, scalability and performance in managing game worlds.
* Python bindings (pyshake) created using Pybind11, that enable you to easily script your own games.
* Uses modern c++ features such as any, variant, visit and fold expressions.
* Uses custom (pre-c++20) ranges inspired by Python ranges and Boost Range.

Shake uses CMake for build management, but actually uses Python for target specification.  
The corresponding CMakeLists.txt is generate automatically using my [Cmake Generator](https://github.com/berryvansomeren/cmake_generator).
