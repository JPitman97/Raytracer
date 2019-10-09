#include "Utils.h"
#include "Ray.h"
#include "Camera.h"
#include "Colour.h"
#include "Light.h"
#include "Sphere.h"
#include "Plane.h"
#include <vector>

int winningObjectIndex(std::vector<double> object_intersections) {
	// return the index of the winning intersection
	int index_of_minimum_value;

	// prevent unnessary calculations
	if (object_intersections.size() == 0) {
		// if there are no intersections
		return -1;
	}
	else if (object_intersections.size() == 1) {
		if (object_intersections.at(0) > 0) {
			// if that intersection is greater than zero then its our index of minimum value
			return 0;
		}
		else {
			// otherwise the only intersection value is negative
			return -1;
		}
	}
	else {
		// otherwise there is more than one intersection
		// first find the maximum value

		double max = 0;
		for (int i = 0; i < object_intersections.size(); i++) {
			if (max < object_intersections.at(i)) {
				max = object_intersections.at(i);
			}
		}

		// then starting from the maximum value find the minimum positive value
		if (max > 0) {
			// we only want positive intersections
			for (int index = 0; index < object_intersections.size(); index++) {
				if (object_intersections.at(index) > 0 && object_intersections.at(index) <= max) {
					max = object_intersections.at(index);
					index_of_minimum_value = index;
				}
			}

			return index_of_minimum_value;
		}
		else {
			// all the intersections were negative
			return -1;
		}
	}
}

int main(int argc, char* argv[])
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int aspectRatio = static_cast<double>(WIDTH) / static_cast<double>(HEIGHT);

	const glm::ivec2 winSize(WIDTH, HEIGHT);
	if (!Init(winSize))
		return -1;

	glm::vec3 camPos(3, 1.5, -4);

	glm::vec3 look_at(0, 0, 0);
	glm::vec3 diff_btw(camPos.x - look_at.x, camPos.y - look_at.y, camPos.z - look_at.z);

	//Possible issue with -diff
	glm::vec3 camDir = glm::normalize(-diff_btw);
	glm::vec3 camPitch = glm::normalize(glm::cross(glm::vec3(0, 1, 0), camDir));
	glm::vec3 camRoll = glm::cross(camPitch, camDir);
	Camera sceneCam(camPos, camDir, camPitch, camRoll);
	
	Colour whiteLight(glm::vec4(255.0f, 255.0f, 255.0f, 0));
	Colour prettyGreen(glm::vec4(59, 220, 64, 0.3f));
	Colour maroon(glm::vec4(179, 93, 43, 0));
	Colour grey(glm::vec4(0.5f, 0.5f, 0.5f, 0));
	Colour black(glm::vec4(0, 0, 0, 0));

	glm::vec3 lightPos(-7, 10, -10);
	Light sceneLight(lightPos, whiteLight);

	// scene objects
	Sphere scene_sphere(glm::vec3(0, 0, 0), 1, prettyGreen);
	Sphere scene_sphere2(glm::vec3(3, 0, 0), 0.5, maroon);
	Plane scene_plane(glm::vec3(0, 1, 0), -1, whiteLight);
	std::vector<Object*> scene_objects;
	scene_objects.push_back(dynamic_cast<Object*>(&scene_sphere));
	scene_objects.push_back(dynamic_cast<Object*>(&scene_sphere2));
	scene_objects.push_back(dynamic_cast<Object*>(&scene_plane));

	double xamnt, yamnt;
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			// No AA
			if (WIDTH > HEIGHT) {
				// the image is wider than it is tall
				xamnt = ((x + 0.5) / WIDTH) * aspectRatio - (((WIDTH - HEIGHT) / static_cast<double>(HEIGHT)) / 2);
				yamnt = ((HEIGHT - y) + 0.5) / HEIGHT;
			}
			else if (HEIGHT > WIDTH) {
				// the image is taller than it is wide
				xamnt = (x + 0.5) / WIDTH;
				yamnt = (((HEIGHT - y) + 0.5) / HEIGHT) / aspectRatio - (((HEIGHT - WIDTH) / static_cast<double>(WIDTH)) / 2);
			}
			else {
				// the image is square
				xamnt = (x + 0.5) / WIDTH;
				yamnt = ((HEIGHT - y) + 0.5) / HEIGHT;
			}

			//All of below is probably messed up
			glm::vec3 camRayPos = sceneCam.getPosition();
			glm::vec3 t (camRoll.x * (yamnt - 0.5), camRoll.y * (yamnt - 0.5), camRoll.z * (yamnt - 0.5));
			glm::vec3 f(camPitch.x * (xamnt - 0.5), camPitch.y * (xamnt - 0.5), camPitch.z * (xamnt - 0.5));
			glm::vec3 h = t + f;
			glm::vec3 camRayDir = camDir + h;

			Ray ray(camRayPos, camRayDir);

			std::vector<double> intersections;

			intersections.reserve(scene_objects.size());
			for (auto& object : scene_objects)
			{
				intersections.push_back(object->findIntersection(ray));
			}

			int index_of_winning_object = winningObjectIndex(intersections);
			//std::cout << index_of_winning_object << std::endl;

			if (index_of_winning_object == -1)
			{
				DrawPixel(glm::ivec2(x, y), glm::ivec3(0, 0, 0));
			}
			else 
			{ 
				//Get object colour and draw pixel 
				Colour objColour = scene_objects.at(index_of_winning_object)->getColor();
				DrawPixel(glm::ivec2(x, y), glm::ivec3(
					objColour.getColour().r, 
					objColour.getColour().g,
					objColour.getColour().b));
				//std::cout << objects.at(index_of_winning_object)->getColor().getColour().r << std::endl;
			}
		}
	}

	std::cout << "Finished rendering" << std::endl;
	ShowAndHold();
}
