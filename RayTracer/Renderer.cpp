#include "Renderer.h"

void Renderer::render(std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	std::thread rThread1(renderThrdQ1, HEIGHT / 2, WIDTH / 2, std::ref(_spheres), std::ref(_lights));
	std::thread rThread2(renderThrdQ1, HEIGHT / 2 + HEIGHT / 2, WIDTH / 2, std::ref(_spheres), std::ref(_lights));
	std::thread rThread3(renderThrdQ1, HEIGHT / 2, WIDTH / 2 + WIDTH / 2, std::ref(_spheres), std::ref(_lights));
	std::thread rThread4(renderThrdQ1, HEIGHT / 2 + HEIGHT / 2, WIDTH / 2 + WIDTH / 2, std::ref(_spheres), std::ref(_lights));
	rThread1.join();
	rThread2.join();
	rThread3.join();
	rThread4.join();
}

void Renderer::renderThrdQ1(int j, int i, std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	for (int height = 0; height < j; height++)
	{
		for (int width = 0; width < i; width++)
		{
			float x = (2 * (width + 0.5) / (float)WIDTH - 1) * tan(fov / 2.) * WIDTH / (float)HEIGHT;
			float y = -(2 * (height + 0.5) / (float)HEIGHT - 1) * tan(fov / 2.);
			glm::vec3 dir = glm::normalize(glm::vec3(x, y, -1));
			Ray ray;
			glm::vec3 col = glm::clamp(ray.castRay(glm::vec3(0, 0, 0), dir, _spheres, _lights),0.0f,1.0f) * 255.0f;
			MCG::DrawPixel(glm::ivec2(width, height), col);
		}
	}
}
