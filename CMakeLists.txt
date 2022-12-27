cmake_minimum_required(VERSION 3.24)
project(untitled2)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled2 main.cpp)

target_link_libraries(untitled2 ${OPENGL_LIBRARIES})
target_link_libraries(untitled2 ${GLUT_LIBRARIES})
target_link_libraries(untitled2 -lopengl32 -g -lfreeglut)