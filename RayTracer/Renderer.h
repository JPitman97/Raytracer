#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <vector>
#include "Sphere.h"
#include "Light.h"
#include "Utils.h"
#include "Ray.h"
#include "ThreadManager.h"
#include <thread>
#include <SDL/SDL_stdinc.h>
#include <mutex>

class Renderer
{
public:
	static void renderThread(int xStart, int xEnd, std::vector<Sphere>& _spheres, std::vector<Light>& _lights);

private:
	//FOV used to create the viewspace
	static const int fov = M_PI / 3.;
};

#endif
