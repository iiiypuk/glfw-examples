/*
  GLFW3 window icon
  Source: https://github.com/IIIypuk/glfw-examples
*/

#include <windows.h>
#include <GLFW/glfw3.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
  LPSTR lpszCmdLine, int nShowCmd)
{
  GLFWwindow *window;
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  window = glfwCreateWindow(192, 64, "Windows icon", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window))
  {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
