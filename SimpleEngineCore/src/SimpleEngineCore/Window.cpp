#include "SimpleEngineCore/Window.hpp"
#include "SimpleEngineCore/Log.hpp"

#include<glad/glad.h>
#include <GLFW/glfw3.h>

namespace SimpleEngine {
    static bool s_GLFW_initialized = false;
	Window::Window(std::string title, const unsigned int width, const unsigned int height)
		: m_title(std::move(title))
		, m_width(width)
		, m_height(height)
	{
		int resultCode = init();
	}
	Window::~Window()
	{
		shutdown();
	}
	int Window::init()
	{

        LOG_INFO("Creating window '{0}' width size {1}x{2}",m_title, m_width, m_height);

        if (!s_GLFW_initialized) {

            if (!glfwInit()) 
            {
                LOG_CRITICAL("Can't initialize GLFW!");
                return -1;
            }
            s_GLFW_initialized = true;
        }

        m_pwindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

        if (!m_pwindow)
        {
            LOG_CRITICAL("Can't create window {0} width size {1}x{2}", m_title, m_width, m_height);
            glfwTerminate();
            return -2;
        }


        glfwMakeContextCurrent(m_pwindow);


        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRITICAL("failed to initialized GLAD");
            return -3;
        }

        return 0;

 

	}
	void Window::shutdown()
	{
        glfwDestroyWindow(m_pwindow);
        glfwTerminate();

	}
	void Window::on_update()
	{
        glClearColor(1, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_pwindow);
        glfwPollEvents();

	}
}