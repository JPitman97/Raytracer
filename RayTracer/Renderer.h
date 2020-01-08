#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <vector>
#include "Sphere.h"
#include "Light.h"
#include "Utils.h"
#include "Ray.h"
#include <thread>
#include <SDL/SDL_stdinc.h>

class Renderer
{
public:
	static void render(std::vector<Sphere>& _spheres, std::vector<Light>& _lights);

	static void renderThrdQ1(int j, int i, std::vector<Sphere>& _spheres, std::vector<Light>& _lights);

private:
	static const int fov = M_PI / 3.;
};

#endif
