# libre-engine
The libre engine is a game engine written in C++, 
for a GNU/Linux distribution, using OpenGL, Lua, and SDL2.

# Building

## The dependencies are as follows:

`cmake`

`Lua 5.2`

`SDL2`

`SDL2 Image`

`GLEW`

Editor:

`Qt 5`

`qmake`

On a Debian-based distro, they can be installed as follows:

    sudo apt-get install cmake && liblua5.2-dev && libsdl2-dev &&\
    && libsdl2-image-dev && libglew-dev && qtbase5-dev && qt5-qmake

To build the engine, first compile and install the libraries:

    #generate the CMake file
    cmake .
    make all
    sudo make install

To compile the Editor, `cd` into `Editor/Libre-Editor/`, then:

    qmake
    make

To compile the demo game, `cd` into `Sandbox/`, then use `make`
