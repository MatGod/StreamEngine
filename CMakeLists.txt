cmake_minimum_required(VERSION 3.17)
project(StreamEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

add_subdirectory(glfw)
include_directories(glfw/include)

set(ZLIB_LIBRARY "libpng/zlib")
add_subdirectory(libpng)
include_directories(libpng)

add_executable(StreamEngine main.cpp GLWindow.cpp GLWindow.h Image.cpp Image.h)

target_link_libraries(StreamEngine glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${PNG_LIBRARIES})