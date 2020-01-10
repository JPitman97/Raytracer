#include "ThreadManager.h"

//Constructor get's the amount of threads available on the system and stores it
ThreadManager::ThreadManager()
{
	threadAmount = std::thread::hardware_concurrency();
}

//Returns the amount of threads
unsigned ThreadManager::getThreadAmount() const
{
	return threadAmount;
}

//Prints the amount of threads to the user and runs the raytracer with a single thread, then half the total threads and finally all threads
void ThreadManager::start(std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	std::cout << "There are " << threadAmount << " threads available on this system" << std::endl;
	std::cout << std::endl;

	renderWithThreads(1, _spheres, _lights); //Render with one thread

	renderWithThreads(threadAmount / 2, _spheres, _lights); //Render with half of the total threads

	renderWithThreads(threadAmount, _spheres, _lights); //Render with all threads
}

void ThreadManager::renderWithThreads(int _threadCount, std::vector<Sphere>& _spheres, std::vector<Light>& _lights)
{
	std::cout << "Rendering with " << _threadCount << " threads" << std::endl;

	xSplit = WIDTH / _threadCount; //Each thread will handle a section of the screen

	auto start = std::chrono::high_resolution_clock::now(); //Start the timer to record the render length


	for (int i = 0; i <= _threadCount; i++) //Loop through the total threads
	{
		//Call the thread and pass in the sections to be rendered, along with the references to the spheres and lights
		threads.emplace_back(Renderer::renderThread, xSplit * i, xSplit * (i + 1), std::ref(_spheres), std::ref(_lights));
	}

	//Loop through all threads and join them back up
	for (auto& thread : threads)
	{
		thread.join();
	}
	threads.clear(); //Clear the threads list

	auto end = std::chrono::high_resolution_clock::now(); //End the timer

	int milli = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//Print the time in seconds and milliseconds
	std::cout << "Finished rendering frame, Duration: " << milli / 1000 << " seconds or " << milli << " milliseconds" << std::endl;
}