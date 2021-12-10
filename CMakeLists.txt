cmake_minimum_required(VERSION 3.10)
project (roguelike-firststab)
set(SDL2_DIR "C:/msys64/mingw64/bin/vcpkg/installed/x64-mingw-static/share/sdl2")
set(glad_DIR "C:/msys64/mingw64/bin/vcpkg/installed/x64-mingw-static/share/glad")
set(lodepng-c_DIR "C:/msys64/mingw64/bin/vcpkg/installed/x64-mingw-static/share/lodepng-c")
set(libtcod_DIR "C:/msys64/mingw64/bin/vcpkg/installed/x64-mingw-static/share/libtcod")
find_package(libtcod CONFIG REQUIRED)
add_executable(roguelike-firststab main.cpp)
target_link_libraries(roguelike-firststab PRIVATE libtcod::libtcod)
add_definitions(-DSDL_MAIN_HANDLED)
#set(CPM_DOWNLOAD_VERSION 0.31.1)
#set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

#if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
#    message(STATUS "Downloading CPM.cmake")
#    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
#endif()

#include(${CPM_DOWNLOAD_LOCATION})
#CPMAddPackage(
#  NAME SDL2
#  VERSION 2.0.18
#  URL https://libsdl.org/release/SDL2-2.0.18.zip
#)
#if (SDL2_ADDED)
#  add_library(SDL2::SDL2 ALIAS SDL2)
#endif()

#CPMAddPackage("gh:libtcod/libtcod#1.19.0")
