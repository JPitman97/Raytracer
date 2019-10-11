
#include "Sphere.h"
#include "Renderer.h"
#include "Light.h"
#include "Utils.h"

int main()
{
	if (!Init(glm::ivec2(WIDTH, HEIGHT)))
		return -1;

	Material ivory(glm::ivec3(255, 0.4, 0));
	Material red_rubber(glm::ivec3(0.3, 255, 0.1));

	std::vector<Sphere> spheres;
	spheres.emplace_back(glm::vec3(-3, 0, -16), 2, ivory);
	spheres.emplace_back(glm::vec3(-1.0, -1.5, -12), 2, red_rubber);
	spheres.emplace_back(glm::vec3(1.5, -0.5, -18), 3, red_rubber);
	spheres.emplace_back(glm::vec3(7, 5, -20), 4, ivory);

	std::vector<Light>  lights;
	lights.emplace_back(glm::vec3(-20, 20, 20), 0.5);

	Renderer::render(spheres, lights);

	std::cout << "Finished rendering" << std::endl;
	ShowAndHold();
	return 0;
}
