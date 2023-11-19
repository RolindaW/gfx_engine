#pragma once

#pragma region Include

#include <GL/gl3w.h>  // Extension loading library
#include <GLFW/glfw3.h>  // Window/Context creation library
//#include <glm/glm.hpp>  //  3D math library

#include <stdio.h>
//#include <math.h>

#pragma endregion

namespace GfxEngineCore
{
	class Application
	{
	protected:
		GLFWwindow* window;

	public:
		virtual ~Application();

	public:
		int Initialize();
		void Run();
		void Terminate();

	protected:
		virtual int InitializeWindow();
		virtual int InitializeGraphics();
		virtual void TerminateWindow();
	};
}
