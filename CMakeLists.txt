cmake_minimum_required(VERSION 3.22)

project(WorldAtWar VERSION 0.1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

set(TGUI_BACKEND SFML_GRAPHICS CACHE STRING "" FORCE)
set(TGUI_BUILD_FRAMEWORK OFF CACHE BOOL "" FORCE)
FetchContent_Declare(TGUI
        GIT_REPOSITORY https://github.com/texus/TGUI.git
        GIT_TAG v1.5.0)
FetchContent_MakeAvailable(TGUI)

set(SFML_STATIC_LIBRARIES OFF CACHE BOOL "" FORCE)

add_subdirectory(waw)