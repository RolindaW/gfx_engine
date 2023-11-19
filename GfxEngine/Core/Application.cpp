#include "Application.h"

namespace GfxEngineCore
{
	// Destructor
	Application::~Application()
	{
		Application::Terminate();
	}

	// Initialize resources required by the application
	int Application::Initialize()
	{
		if (Application::InitializeWindow()) return -1;
		if (Application::InitializeGraphics()) return -1;

		return 0;
	}

	// Run loop of the application
	void Application::Run()
	{
		// If it is initialized...
		// TODO: Before run, it is neccesary to specify the scene, load it, then run. For the moment, enough with this loop.

		// Loop until the user closes the window
		while (!glfwWindowShouldClose(window))
		{
			// Clear the framebuffer with dark green
			static const GLfloat color[] = { 0.0f, 0.2f, 0.0f, 1.0f };
			glClearBufferfv(GL_COLOR, 0, color);

			// Swap front and back buffers
			glfwSwapBuffers(window);

			// Poll for and process events
			glfwPollEvents();
		}
	}

	// Terminate allocated resources by the application
	void Application::Terminate()
	{
		Application::TerminateWindow();
	}

	// Initialize window (and context)
	int Application::InitializeWindow()
	{
		// Initialize GLFW library
		if (!glfwInit())
		{
			fprintf(stderr, "failed to initialize glfw\n");
			return -1;
		}

		// Create a windowed mode window and its OpenGL context
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			fprintf(stderr, "failed to initialize window\n");
			glfwTerminate();
			return -1;
		}

		// Make the window's context current
		glfwMakeContextCurrent(window);

		return 0;
	}

	// Initialize graphics library
	int Application::InitializeGraphics()
	{
		// Initialize OpenGL functions loading library
		if (gl3wInit()) {
			fprintf(stderr, "failed to initialize OpenGL\n");
			return -1;
		}

		// Check requried version
		if (!gl3wIsSupported(4, 5)) {
			fprintf(stderr, "OpenGL 4.5 not supported\n");
			return -1;
		}

		// Print active OpenGL and GLSL versions
		printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
			glGetString(GL_SHADING_LANGUAGE_VERSION));

		return 0;
	}

	// Terminate window
	void Application::TerminateWindow()
	{
		glfwTerminate();
	}
}
