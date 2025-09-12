#include <std.h>
#include <glad.h>
#include <glfw.h>

#ifdef key_callback
#else
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {return;}
#endif

void error_callback(int error, const char* description) {
    printf("ERR: %s\n", description);
    return;
}

GLFWwindow* low_createwindow(int width, int height, char title[]) {
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, title, 0, 0);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);

    glfwSetErrorCallback(error_callback);
    glfwSetKeyCallback(window, key_callback);

    if (!window) {printf("ERR: window failed to initialise"); return NULL;}
    return window;
}

void closewindow(GLFWwindow *window) {
    glfwDestroyWindow(window);
    return;
}

// set window close flag
void SWCflag(GLFWwindow *window) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
    return;
}

void openloop(GLFWwindow *window, uint delay, uint32 data, void (*fn)(GLFWwindow*,uint32)) {
    while (!glfwWindowShouldClose(window)) {
        fn(window,data);
        sleep(delay);
    }
    return;
}