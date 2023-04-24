cmake_minimum_required(VERSION 3.20)

project(unittest)
add_executable(unittest
        src/main.cpp
        src/BasicTest.hpp src/ContextTest.hpp src/LongTest.hpp)
target_compile_features(unittest PRIVATE cxx_std_17)
target_link_libraries(unittest PRIVATE erbsland-unittest-example-lib)
target_include_directories(unittest PRIVATE ../erbsland-unittest/include)
target_include_directories(unittest PRIVATE ../example-lib/src)
erbsland_unittest(TARGET unittest)

