/*
  GLFW3 frame rate counter example
  Source: https://github.com/IIIypuk/glfw-examples

  Compile: gcc fps_counter.c -lglfw -lGL
*/

#include <stdio.h>
#ifndef _WIN32
  #include <windows.h>
#endif
#include "GLFW/glfw3.h"

int main()
{
  GLFWwindow *window;
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  window = glfwCreateWindow(400, 400, "FPS Counter", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  int frames = 0;
  double t, t0, fps;
  char title_string[10];

  t0 = glfwGetTime();

  while (!glfwWindowShouldClose(window))
  {
    glClearColor(0.2, 0.8, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(1, 0.2, 0.2, 0);
    glBegin(GL_POLYGON);
      glColor3f(0.4, 0.3, 1.0);
        glVertex3f(-0.8,  0.8, 0.0);
        glVertex3f( 0.8,  0.8, 0.0);
        glVertex3f( 0.8, -0.8, 0.0);
        glVertex3f(-0.8, -0.8, 0.0);
    glEnd();

    t = glfwGetTime();

    if((t - t0) > 1.0 || frames == 0)
    {
      fps = (double)frames / (t - t0);
      sprintf(title_string, "FPS: %.1f", fps);
      glfwSetWindowTitle(window, title_string);
      t0 = t;
      frames = 0;
    }
    frames ++;

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
