cmake_minimum_required(VERSION 3.12)

project(scop_42)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/main.cpp
    src/glad.c
)

set(HEADERS
    include/object.hpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(scop ${SOURCES} ${HEADERS})

target_include_directories(scop PRIVATE include)

target_link_directories(scop PRIVATE lib/GLFW)

target_link_libraries(scop glfw3 "-framework cocoa -framework IOKit -framework CoreVideo -framework OpenGL")