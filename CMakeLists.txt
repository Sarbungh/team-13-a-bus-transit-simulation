cmake_minimum_required(VERSION 3.18)
project(raylib_fun_starter C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.0
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE raylib)

if (WIN32)
  target_link_libraries(game PRIVATE winmm gdi32)
endif()