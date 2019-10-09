#include "Utils.h"


int main(int argc, char* argv[])
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	glm::ivec2 winSize(WIDTH, HEIGHT);
	if (!Init(winSize))
		return -1;


	return ShowAndHold();
}