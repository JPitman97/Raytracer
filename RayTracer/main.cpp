#include "Sphere.h"
#include "Renderer.h"
#include "Light.h"
#include "Utils.h"

int main()
{
	if (!MCG::Init(glm::ivec2(WIDTH, HEIGHT)))
		return -1;

	//Material(Albedo, Colour, Specular)
	Material LimeMat(glm::vec2(0.6, 0.3), glm::vec3(3, 252, 111), 50.0f);
	Material BlueMat(glm::vec2(0.7, 0.9), glm::vec3(2, 140, 245), 20.0f); // Clipping
	Material PinkMat(glm::vec2(0.5, 0.6), glm::vec3(240, 14, 191), 30.0f);

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
	lights.emplace_back(glm::vec3(-20, 20, 20), 0.5f);
	lights.emplace_back(glm::vec3(30, 50, -25), 0.8);
	lights.emplace_back(glm::vec3(30, 20, 30), 0.7);

	MCG::SetBackground(glm::ivec3(255, 255, 255));
	Renderer::render(spheres, lights);

	std::cout << "Finished rendering" << std::endl;
	MCG::ShowAndHold();

	return 0;
}
