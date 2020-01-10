#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include "SDL/SDL.h"
#include "GLM/glm.hpp"
#include <vector>
#include <algorithm>

#undef main()

// MCG_GFX_LIB - Supplied by Bournemouth University

const int WIDTH = 640;
const int HEIGHT = 480;

namespace MCG
{
	bool Init(glm::ivec2 windowSize);

	void SetBackground(glm::ivec3 colour);

	void DrawPixel(glm::ivec2 position, glm::ivec3 colour);

	bool ProcessFrame();

	void Cleanup();

	int ShowAndHold();
}

float clamp(float n, float lower, float upper);
#endif
