cmake_minimum_required(VERSION 3.20)

project(Raab-bot)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(Raab-bot
        main.cpp
        src/Board.cpp
        src/Eval.cpp
        src/Game_State.cpp
        src/Node.cpp
        src/Search.cpp
        src/Square.cpp
        src/UCI.cpp)
target_include_directories(Raab-bot PRIVATE include)

enable_testing()
include(CTest)

add_subdirectory(test)
