#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <vector>
#include "Sphere.h"
#include "Light.h"
#include "Utils.h"
#include "Ray.h"
#include <SDL/SDL_stdinc.h>

class Renderer
{
public:
	static void render(std::vector<Sphere>& _spheres, std::vector<Light>& _lights);
};

#endif
