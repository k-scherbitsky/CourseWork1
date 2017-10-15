cmake_minimum_required(VERSION 3.7)
project(CourseWork)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp

        Struct/struct.h
        Stack/stack.cpp
        Stack/stack.h
        Menu/menu.cpp
        Menu/menu.h
        Constants/constChar.h
        Database/database.cpp
        Database/database.h
        InputOutput/input_output.cpp
        InputOutput/input_output.h
        Sorting/sorting.cpp
        Sorting/sorting.h
        Constants/constInt.h
        Search/search.cpp
        Search/search.h)
add_executable(CourseWork ${SOURCE_FILES})

set(CMAKE_EXE_LINKER_FLAGS "-static")