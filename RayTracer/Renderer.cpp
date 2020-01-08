#include "Renderer.h"

void Renderer::render(std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	unsigned int coreAmount = std::thread::hardware_concurrency();
	std::cout << coreAmount << std::endl;
	unsigned int xSplit = WIDTH / coreAmount;
	unsigned int ySplit = HEIGHT / coreAmount;
	std::vector<std::thread> threads;
	for (size_t i = 1; i <= coreAmount + 1; i++)
	{
		std::thread rThread();
		threads.emplace_back(RenderThread, ySplit * i, xSplit * i, std::ref(_spheres), std::ref(_lights));
	}
	for (size_t i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}
}

void Renderer::RenderThread(int j, int i, std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
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
