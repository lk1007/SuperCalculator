cmake_minimum_required(VERSION 3.16.3)

project(calculator)

set(sources main.cpp calculator.cpp func.h)
add_executable(${PROJECT_NAME} main.cpp calculator.cpp func.h)

add_custom_target(run
    COMMAND calculator
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    SOURCES ${sources}
)