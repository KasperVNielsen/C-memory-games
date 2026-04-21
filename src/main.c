#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>


long generateNumber(int digits)
{
    long min = 1;
    for (int i = 1; i < digits; i++)
        min *= 10;

    long max = min * 10 - 1;

    return min + rand() % (max - min + 1);
}

int main(void)
{
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Black Window", NULL, NULL);
    if (!window) {
        printf("Failed to create window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Set clear color to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
