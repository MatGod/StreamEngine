cmake_minimum_required(VERSION 3.17)
project(StreamEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)

add_subdirectory(Libs/glfw)
include_directories(Libs/glfw/include)

find_package(PNG REQUIRED)

set(png++_ROOT_DIR "Libs/pngpp")
set(png++_INCLUDE_DIRS "Libs/pngpp")

include_directories(${png++_INCLUDE_DIRS})

add_executable(StreamEngine
        main.cpp
        LowLevel/Render/GLWindow.cpp LowLevel/Render/GLWindow.h
        LowLevel/Images/Image.cpp LowLevel/Images/Image.h
        LowLevel/Render/Render.cpp LowLevel/Render/Render.h
        LowLevel/Render/Shader.cpp LowLevel/Render/Shader.h
        HighLevel/Scene.cpp HighLevel/Scene.h HighLevel/Game.cpp HighLevel/Game.h HighLevel/GameObject.cpp HighLevel/GameObject.h LowLevel/Images/Drawable.cpp LowLevel/Images/Drawable.h LowLevel/Images/Animation.cpp LowLevel/Images/Animation.h)

target_link_libraries(StreamEngine GL glfw GLEW EGL ${PNG_LIBRARY} ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} ${png++_LIBRARIES})