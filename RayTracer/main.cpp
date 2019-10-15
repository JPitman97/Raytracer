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


	//std::cout << "Finished rendering" << std::endl;
	//ShowAndHold();

	// Variable to keep track of time
	float timer = 0.0f;
	while (MCG::ProcessFrame())
	{
		// Set every pixel to the same colour
		MCG::SetBackground(glm::ivec3(0, 0, 0));

		// Change our pixel's X coordinate according to time
		const glm::vec3 spherePos = spheres[1].getSphereCenter();
		spheres[1].setSphereCenter(glm::vec3(spherePos.x, sin(5 * timer) * 5, spherePos.z));
		// Update our time variable
		timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		Renderer::render(spheres, lights);
	}

	return 0;
}
