#include "Sphere.h"
#include "ThreadManager.h"
#include "Light.h"
#include "Utils.h"

int main()
{
	//Initialise MCG AND SDL
	if (!MCG::Init(glm::ivec2(WIDTH, HEIGHT)))
		return -1;

	//Create materials to be applied to spheres
	//Material(Colour, Specular)
	Material LimeMat(glm::vec3(0.01f, 0.9f, 0.48f), 32.0f);
	Material BlueMat(glm::vec3(0.01f, 0.55f, 0.95f), 10.0f);
	Material PinkMat(glm::vec3(0.9f, 0.1f, 0.8f), 450.5f);

	//Create a vector to hold spheres created below
	std::vector<Sphere> spheres;
	//Sphere(Center, Radius, Material)
	spheres.emplace_back(glm::vec3(-6, -3, -16), 1, BlueMat);
	spheres.emplace_back(glm::vec3(0, -3, -16), 2, LimeMat); //Center sphere
	spheres.emplace_back(glm::vec3(6, -3, -16), 3, PinkMat);

	spheres.emplace_back(glm::vec3(-6, 5, -20), 2, LimeMat);
	spheres.emplace_back(glm::vec3(0, 5, -20), 2, PinkMat); //Center sphere
	spheres.emplace_back(glm::vec3(6, 5, -20), 2, BlueMat);

	//Create a vector to hold lights created below
	std::vector<Light> lights;
	//Light(Position, Intensity(0-1))
	lights.emplace_back(glm::vec3(0, 20, 0), 1.0f);
	lights.emplace_back(glm::vec3(30, 0, 0), 0.6);
	lights.emplace_back(glm::vec3(30, 20, 30), 0.5);

	//Set the window background to black, in case objects fail to render
	MCG::SetBackground(glm::ivec3(255, 255, 255));

	//Create an instance of ThreadManager, which handles multi threading
	ThreadManager threadManager;
	//Start the thread manager and pass in the spheres and lights vector
	threadManager.start(spheres, lights);

	//Print that the rendering process has entirely finished
	std::cout << "Finished rendering all frames" << std::endl;

	//Keep the window open until the user closes it
	MCG::ShowAndHold();

	//Return
	return 0;
}
