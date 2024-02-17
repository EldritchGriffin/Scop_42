#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GraphicsManager
{
private:
    GLFWwindow *_window;
    GLuint _shaderProgram;

public:
    GraphicsManager();
    ~GraphicsManager();
    void init();
    void initShaders();
    void terminate();
    void createWindow(int width, int height, const char *title, GLFWframebuffersizefun framebuffer_size_callback);
    void processInput(GLFWwindow *window);
    void run();
    GLFWwindow *getWindow();
};
