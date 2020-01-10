#include "Renderer.h"

//Mutex used to lock the Render methods while being accessed, to stop multiple threads from trying to draw at the same time
std::mutex renderMutex;
int heightT = 0, widthT = 0;

//Main render method, parameters are j (Height) and i (Width), plus the spheres and lights vectors created in main()
void Renderer::renderThread(int xStart, int xEnd, std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	//Loop through both height and width, going in rows
	for (int height = 0; height < HEIGHT; height++)
	{
		for (int width = xStart; width < xEnd; width++)
		{
			//Create an arc using tan which becomes the viewspace 
			float x = (2 * (width + 0.5) / static_cast<float>(WIDTH) - 1) * tan(fov / 2.) * WIDTH / static_cast<float>(HEIGHT);
			float y = -(2 * (height + 0.5) / static_cast<float>(HEIGHT) - 1) * tan(fov / 2.);
			//Get a direction vector aiming forward
			glm::vec3 dir = glm::normalize(glm::vec3(x, y, -1));
			//Create an instance of ray, to use it's castRay method, passing in the origin (Center), as well as the previous direction
			//and the spheres and lights vector
			Ray ray;
			//Retrieve the colour the ray hit and clamp it between 0 and 1, before multiplying it by 255 to get the correct colour value
			glm::vec3 col = glm::clamp(ray.castRay(glm::vec3(0, 0, 0), dir, _spheres, _lights),0.0f,1.0f) * 255.0f;
			//Lock the mutex to prevent multiple threads trying to draw
			renderMutex.lock();
			//Draw the pixel hit by the ray
			MCG::DrawPixel(glm::ivec2(width, height), col);
			//Unlock the mutex so another thread can draw
			renderMutex.unlock();
		}
	}
}
