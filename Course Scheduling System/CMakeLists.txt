cmake_minimum_required(VERSION 3.28)
project(StartingMenu)

set(CMAKE_CXX_STANDARD 17)
include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)
add_executable(StartingMenu main.cpp
        startingMenu.h
        startingMenu.cpp
        chooseCourse.cpp
        chooseCourse.h
        tools.cpp
        tools.h
        courseManage.cpp)
