cmake_minimum_required(VERSION 3.25)
project(DatabaseAccessController)

set(CMAKE_CXX_STANDARD 20)

add_library(DatabaseAccessController STATIC
        DatabaseAccessController.cpp
        DatabaseAccessingObject.cpp
)

target_include_directories(DatabaseAccessController PUBLIC include)
target_link_libraries(DatabaseAccessController PUBLIC SQLiteCpp)
