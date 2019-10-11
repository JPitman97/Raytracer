#include "Utils.h"
#include "Sphere.h"
#include "Ray.h"
#include <algorithm>

void render(std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	const int fov = M_PI / 3.;

	for (size_t j = 0; j < HEIGHT; j++)
	{
		for (size_t i = 0; i < WIDTH; i++)
		{
			float x = (2 * (i + 0.5) / (float)WIDTH - 1) * tan(fov / 2.) * WIDTH / (float)HEIGHT;
			float y = -(2 * (j + 0.5) / (float)HEIGHT - 1) * tan(fov / 2.);
			glm::vec3 dir = glm::normalize(glm::vec3(x, y, -1));
			Ray ray;
			DrawPixel(glm::ivec2(i, j), ray.castRay(glm::vec3(0, 0, 0), dir, _spheres, _lights));
		}
	}
}

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
	spheres.emplace_back(glm::vec3(7, 5, -18), 4, ivory);

	std::vector<Light>  lights;
	lights.emplace_back(glm::vec3(-20, 20, 20), 0.5);

	render(spheres, lights);

	std::cout << "Finished rendering" << std::endl;
	ShowAndHold();
	return 0;
}
