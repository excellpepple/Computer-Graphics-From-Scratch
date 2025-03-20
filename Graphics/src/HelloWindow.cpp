#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Callback function to adjust viewport when the window is resized
    // Resize the viewport to fit the new window dimensions
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}

int main(int argc, char* argv[])
{

    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a window
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Set up GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to intitialize GLAD\n";
        return -1;
    }

    // Set viewport size
    glViewport(0,0,WINDOW_WIDTH, WINDOW_HEIGHT);
    // Set callback for window resize event
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // Input processing
        processInput(window);

        // render commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);



        // check, call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // Cleanup
    glfwTerminate();
    return 0;
}
