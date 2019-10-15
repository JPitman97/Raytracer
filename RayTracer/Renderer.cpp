#include "Renderer.h"

void Renderer::render(std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
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
			MCG::DrawPixel(glm::ivec2(i, j), ray.castRay(glm::vec3(0, 0, 0), dir, _spheres, _lights));
		}
	}
}
