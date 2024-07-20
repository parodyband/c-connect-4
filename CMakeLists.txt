cmake_minimum_required(VERSION 3.10)
project(ConnectFour CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src/core)
include_directories(${CMAKE_SOURCE_DIR}/src/graphics)
include_directories(${CMAKE_SOURCE_DIR}/src/math)

# Add source files
add_executable(${PROJECT_NAME}
        src/main/main.cpp
        src/graphics/Renderer.cpp
        src/core/Global.cpp
        src/core/Entity.cpp
        include/raymath.h
        src/math/Utils.cpp
        src/math/Utils.h
        src/core/Bag.cpp
        src/core/Bag.h
        src/core/Board.cpp
        src/core/Board.h
)

# Create a custom target to copy resources
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "Copying resources to build directory"
)

# Ensure the executable depends on the copy_resources target
add_dependencies(${PROJECT_NAME} copy_resources)

# Link Raylib
target_link_libraries(${PROJECT_NAME} raylib)
