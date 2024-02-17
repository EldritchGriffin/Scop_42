#include <iostream>
#include <GraphicsManager.hpp>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE

const char *vertexShaderSource = "#version 120\n"
                                 "void main() {\n"
                                 "   gl_Position = vec4(0.0, 0.0, 0.0, 1.0);\n"
                                 "}";

const char *fragmentShaderSource = "#version 120\n"
                                   "void main() {\n"
                                   "   gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
                                   "}";

GraphicsManager::GraphicsManager()
{
    _window = nullptr;
}

GraphicsManager::~GraphicsManager()
{
    terminate();
}

void GraphicsManager::init()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
}

void GraphicsManager::initShaders()
{
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        throw std::runtime_error("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" + std::string(infoLog));
    }
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        throw std::runtime_error("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" + std::string(infoLog));
    }
    this->_shaderProgram = glCreateProgram();
    glAttachShader(this->_shaderProgram, vertexShader);
    glAttachShader(this->_shaderProgram, fragmentShader);
    glLinkProgram(this->_shaderProgram);
    glGetProgramiv(this->_shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(this->_shaderProgram, 512, NULL, infoLog);
        throw std::runtime_error("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + std::string(infoLog));
    }
    glUseProgram(this->_shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void GraphicsManager::terminate()
{
    if (_window)
    {
        glfwDestroyWindow(_window);
    }
    glfwTerminate();
}

void GraphicsManager::createWindow(int width, int height, const char *title, GLFWframebuffersizefun framebuffer_size_callback)
{
    _window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!_window)
    {
        throw std::runtime_error("Failed to create window");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void GraphicsManager::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void GraphicsManager::run()
{
    while (!glfwWindowShouldClose(_window))
    {
        processInput(_window);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(_window);
    }
}

GLFWwindow *GraphicsManager::getWindow()
{
    return _window;
}