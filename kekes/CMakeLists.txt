
cmake_minimum_required(VERSION 3.16)

project(kekes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BINARY_DIR build/Debug/buil/Debug/generators)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)

set(PROJECT_SOURCES
    main.cpp
    escape_button.cpp
    escape_button.h
    ty_durak.cpp
    ty_durak.h
    ty_durak.ui
)