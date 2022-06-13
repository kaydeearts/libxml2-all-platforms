# Libxml2 All Platforms


This is a minimal working example repo demonstrating how to use ExternalProject_Add to install libxml2 on Mac, Windows and Linux. 
It also supports both CMake and Ninja.

To build with cmake:
`cmake -S . -B build`
`cmake --build . --config Release`

To build with ninja:
`cmake -B build -GNinja`
`cmake --build build`

Good luck!