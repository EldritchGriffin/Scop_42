#include <iostream>
#include <GraphicsManager.hpp>
#include <Object.hpp>

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(int ac, char **av)
{
    GraphicsManager gm;
    try
    {
        gm.init();
        gm.createWindow(800, 600, "Hello World", framebuffer_size_callback);
        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
        gm.initShaders();
        Object triangle(vertices);
        while (!glfwWindowShouldClose(gm.getWindow()))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw the triangle directly without binding any VAO
            glDrawArrays(GL_TRIANGLES, 0, 3);

            glfwSwapBuffers(gm.getWindow());
            glfwPollEvents();
        }
        gm.terminate();
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}