cmake_minimum_required(VERSION 3.16.3)
set(projName calculator)
project(${projName})

set(sources main.cpp calculator.cpp tree.cpp calculations.cpp calculator.h)
enable_testing()
add_subdirectory(googletest)
set(Headers calculator.h)
set(Sources
    calculator.cpp
    tree.cpp
    calculations.cpp

)
add_library(${projName} STATIC ${Sources} ${Headers})
add_subdirectory(test)