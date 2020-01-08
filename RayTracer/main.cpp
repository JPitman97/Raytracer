#include "Sphere.h"
#include "Renderer.h"
#include "Light.h"
#include "Utils.h"

int main()
{
	if (!MCG::Init(glm::ivec2(WIDTH, HEIGHT)))
		return -1;

	//Material(Albedo, Colour, Specular)
	Material LimeMat(glm::vec2(0, 0), glm::vec3(0.01f, 0.9f, 0.48f), 32.0f);
	Material BlueMat(glm::vec2(0, 0), glm::vec3(0.01f, 0.55f, 0.95f), 10.0f); // Clipping
	Material PinkMat(glm::vec2(0, 0), glm::vec3(0.9f, 0.1f, 0.8f), 450.5f);

	std::vector<Sphere> spheres;
	//Sphere(Center, Radius, Material)
	spheres.emplace_back(glm::vec3(-6, -3, -16), 1, BlueMat);
	spheres.emplace_back(glm::vec3(0, -3, -16), 2, LimeMat); //Center sphere
	spheres.emplace_back(glm::vec3(6, -3, -16), 3, PinkMat);

	spheres.emplace_back(glm::vec3(-6, 5, -20), 2, LimeMat);
	spheres.emplace_back(glm::vec3(0, 5, -20), 2, PinkMat); //Center sphere
	spheres.emplace_back(glm::vec3(6, 5, -20), 2, BlueMat);


	std::vector<Light> lights;
	//Light(Position, Intensity(0-1))
	lights.emplace_back(glm::vec3(0, 20, 0), 1.0f);
	lights.emplace_back(glm::vec3(30, 0, 0), 0.6);
	lights.emplace_back(glm::vec3(30, 20, 30), 0.5);

	MCG::SetBackground(glm::ivec3(255, 255, 255));
	Renderer::render(spheres, lights);

	std::cout << "Finished rendering" << std::endl;
	MCG::ShowAndHold();

	return 0;
}
