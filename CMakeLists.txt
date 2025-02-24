cmake_minimum_required(VERSION 3.20)

project(
    "gl_ground"
    VERSION 0.1
    DESCRIPTION "playground for OpenGL"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# src

set(SOURCES
    src/main.cpp
)

# dependencies

find_package(OpenGL REQUIRED)
if (NOT OPENGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()

# output directories

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# glfw

set(GLFW_DIR ${CMAKE_SOURCE_DIR}/vendor/glfw-3.4)

add_subdirectory(${GLFW_DIR})
include_directories(${GLFW_DIR}/include)

# glad

set(GLAD_DIR ${CMAKE_SOURCE_DIR}/vendor/glad)

add_library(glad STATIC ${GLAD_DIR}/src/glad.c)
include_directories(${GLAD_DIR}/include)

# build

add_executable(${PROJECT_NAME} ${SOURCES})

# include directories

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# link libraries

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL glad)
