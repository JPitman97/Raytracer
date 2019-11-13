#include "Sphere.h"
#include "Renderer.h"
#include "Light.h"
#include "Utils.h"

int main()
{
	if (!MCG::Init(glm::ivec2(WIDTH, HEIGHT)))
		return -1;

	Material LimeMat(glm::ivec3(3, 252, 111));
	Material BlueMat(glm::ivec3(2, 140, 245));
	Material PinkMat(glm::ivec3(240, 14, 191));

	std::vector<Sphere> spheres;
	spheres.emplace_back(glm::vec3(-3, 0, -16), 1, BlueMat);
	spheres.emplace_back(glm::vec3(0, 0, -16), 2, LimeMat); //Center sphere
	spheres.emplace_back(glm::vec3(5, 0, -16), 3, PinkMat);


	std::vector<Light> lights;
	lights.emplace_back(glm::vec3(-20, 20, 20), 0.8f);

	MCG::SetBackground(glm::ivec3(255, 255, 255));
	Renderer::render(spheres, lights);

	std::cout << "Finished rendering" << std::endl;
	MCG::ShowAndHold();

	// Variable to keep track of time
	//float timer = 0.0f;
	//while (MCG::ProcessFrame())
	//{
	//	// Set every pixel to the same colour
	//	MCG::SetBackground(glm::ivec3(255, 255, 255));

	//	// Update our time variable
	//	timer += 1.0f / 60.0f;

	//	// Draw the pixel to the screen
	//	Renderer::render(spheres, lights);
	//}

	return 0;
}
