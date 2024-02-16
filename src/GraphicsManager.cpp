#include <iostream>
#include <GraphicsManager.hpp>
#include <exception>

GraphicsManager::GraphicsManager() {
    window = nullptr;
}

GraphicsManager::~GraphicsManager() {
    terminate();
}

void GraphicsManager::init() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
}

void GraphicsManager::terminate() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void GraphicsManager::createWindow(int width, int height, const char* title, GLFWframebuffersizefun framebuffer_size_callback) {
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        throw std::runtime_error("Failed to create window");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        throw std::runtime_error("Failed to initialize GLAD");
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glad_glClearColor(1,1,1,1);
}


void GraphicsManager::processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void GraphicsManager::run() {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glad_glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}