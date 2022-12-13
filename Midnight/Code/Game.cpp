#include "Game.h"

const char* vertexShaderSource = R"(
  #version 330 core
  layout (location = 0) in vec4 vertex; // <vec2 position, vec2 texCoords>

  out vec2 TexCoords;

  uniform mat4 model;
  uniform mat4 projection;

  void main()
  {
    TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
  }
)";

const char* fragmentShaderSource = R"(
  #version 330 core
  in vec2 TexCoords;
  out vec4 color;

  uniform sampler2D image;
  uniform vec3 spriteColor;

  void main()
  {
      color = vec4(spriteColor, 1.0) * texture(image, TexCoords);
  }
)";

Game::Game(unsigned int width, unsigned int height)
    : m_width(width)
    , m_height(height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_window = glfwCreateWindow(m_width, m_height, "NEKO Engine", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

}

Game::~Game()
{
    glfwTerminate();
}

void Game::Init()
{

}

void Game::Run()
{
    while (!glfwWindowShouldClose(m_window))
    {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}