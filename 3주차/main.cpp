#include <GLFW/glfw3.h>

#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include<windows.h>

#define Pi 3.1415

#define GLUT_KEY_UP 101



#pragma comment(lib,"opengL32")



static void error_callback(int error, const char* description)

{

    fputs(description, stderr);

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)

{

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)

        glfwSetWindowShouldClose(window, GL_TRUE);

}


void main()

{

    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())

        exit(EXIT_FAILURE);

    window = glfwCreateWindow(700, 700, "Simple example", NULL, NULL);

    if (!window)

    {

        glfwTerminate();

        exit(EXIT_FAILURE);

    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);



    while (!glfwWindowShouldClose(window))

    {

        float ratio;

        int width, height;

        glfwGetFramebufferSize(window, &width, &height);

        ratio = width / (float)height;




        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.0f, 0.0f, 1.0f);

        double rad = 1.0;       //radius(반지름)의 크기를 1로 고정
        glBegin(GL_LINE_STRIP); //LINE_STRIP으로 직선으로 만든다
        for (int i = 0; i < 360; i++) // 원의 각도가 360도 이므로 
        {
            double angle, x, y;
            angle = i * 3.141592 / 180; //ANGLE(각도)를 맞춘다. 각도 * π/180
            x = rad * cos(angle);
            y = rad * sin(angle);
            glVertex2f(x, y);
        }

        glEnd();
        glFinish();








        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glfwDestroyWindow(window);

    glfwTerminate();

    exit(EXIT_SUCCESS);

}