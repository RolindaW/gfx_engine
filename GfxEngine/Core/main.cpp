
#include <glm/glm.hpp>  //  3D math library

#include "Application.h"

// Note: Main entry point to the application should be tested in a separated project as core is intended to be a library.
int main(void)
{
	// Some GLM code
	glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
	glm::mat4 Model = glm::mat4(1.0);
	Model[3] = glm::vec4(1.0, 1.0, 0.0, 1.0);
	glm::vec4 Transformed = Model * Position;

	GfxEngineCore::Application app;
	if (!app.Initialize())
	{
		app.Run();
		app.Terminate();
	}
}