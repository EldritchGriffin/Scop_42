#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define GLFW_INCLUDE_NONE

class Object
{
private:
    float *_vertices;
    GLuint _VAO;
    GLuint _VBO;

public:
    Object(float vertices[]);
    ~Object();
};
