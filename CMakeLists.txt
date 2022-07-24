cmake_minimum_required(VERSION 3.16.3)

project(calculator)

set(sources main.cpp calculator.cpp tree.cpp calculations.cpp calculator.h)
add_executable(${PROJECT_NAME} ${sources})

add_custom_target(run
    COMMAND calculator
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    SOURCES ${sources}
)