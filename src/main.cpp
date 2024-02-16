#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <GraphicsManager.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glad_glViewport(0, 0, width, height);
}

int main(int ac, char** av){
    GraphicsManager gm;
    try
    {
        gm.init();
        gm.createWindow(800, 600, "Hello World", framebuffer_size_callback);
        gm.run();
        gm.terminate();
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }    
}