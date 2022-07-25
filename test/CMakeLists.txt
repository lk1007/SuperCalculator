cmake_minimum_required(VERSION 3.16.3)
set(projName exampTest)
set(Sources test.cpp)
add_executable(exampTest ${Sources})
target_link_libraries(exampTest PUBLIC
    gtest_main
    calculator
)
add_test(
    NAME ${projName}
    COMMAND $(projName)
)
