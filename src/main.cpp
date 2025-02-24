// clang-format off
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

struct Colors {
    float ONE[4] = {1.0f, 0.0f, 0.0f};
    float TWO[4] = {0.0f, 1.0f, 0.0f};
    float THREE[4] = {0.0f, 0.0f, 1.0f};
    float FOUR[4] = {0.0f, 0.0f, 0.0f};
    int idx = 0;
} col;

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 800, "gl ground", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to open Window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    glViewport(0, 0, 800, 800);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
        glClearColor(col.ONE[col.idx], col.TWO[col.idx], col.THREE[col.idx], col.FOUR[col.idx]);
        col.idx = (col.idx + 1) % 3;
    }
}
