#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_NONE

class GraphicsManager 
{
    private:
        GLFWwindow* window;
        
    public:
        GraphicsManager();
        ~GraphicsManager();
        void init();
        void terminate();
        void createWindow(int width, int height, const char* title, GLFWframebuffersizefun framebuffer_size_callback);
        void processInput(GLFWwindow *window);
        void run();
};
