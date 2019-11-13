#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include "SDL/SDL.h"
#include "GLM/glm.hpp"
#include <vector>

#undef main()

//Formerly MCG_GFX_LIB - Supplied by Bournemouth University

const int WIDTH = 1280;
const int HEIGHT = 720;

namespace MCG
{
	bool Init(glm::ivec2 windowSize);

	void SetBackground(glm::ivec3 colour);

	void DrawPixel(glm::ivec2 position, glm::ivec3 colour);

	bool ProcessFrame();

	void Cleanup();

	int ShowAndHold();

}
#endif
