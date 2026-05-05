#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "games/number_memory.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS || action == GLFW_REPEAT) {
        input_memory_number(key);  // Pass the GLFW key code
    }
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
        // IMPORTANT: Register the key callback function
    glfwSetKeyCallback(window, key_callback);


    // Main loop
    while (!glfwWindowShouldClose(window))
    {
    float time = glfwGetTime();

    glClear(GL_COLOR_BUFFER_BIT);
    init_number_memory();
    update_memory_number(time);
    render_memory_number();

    glfwSwapBuffers(window);
    glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
