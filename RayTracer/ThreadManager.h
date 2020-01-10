#ifndef _THREADMANAGER_H_
#define _THREADMANAGER_H_

#include "Light.h"
#include <vector>
#include "Sphere.h"
#include "Utils.h"
#include "Renderer.h"
#include <thread>
#include <chrono>

class ThreadManager
{
public:
	ThreadManager();

	unsigned int getThreadAmount() const;
	void start(std::vector<Sphere>& _spheres, std::vector<Light>& _lights);
private:
	unsigned int threadAmount = 0;
	unsigned int xSplit = 0;
	unsigned int ySplit = 0;
	std::vector<std::thread> threads;

	//Methods
	void renderWithThreads(int _threadCount, std::vector<Sphere>& _spheres, std::vector<Light>& _lights);
};

#endif