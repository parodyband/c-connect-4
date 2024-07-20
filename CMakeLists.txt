cmake_minimum_required(VERSION 3.10)
project(ConnectFour C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Find Raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )
    FetchContent_MakeAvailable(raylib)
endif()

add_executable(${PROJECT_NAME} src/main.c)

# Link Raylib
target_link_libraries(${PROJECT_NAME} raylib)