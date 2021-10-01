#include <chrono>
#include <ctime>
#include <iostream>

#include "thread_manager.hpp"
#include "texture.hpp"

namespace Core::Engine
{
	ThreadManager::ThreadManager()
	{
		for (int i = 0; i < maxThread; i++)
			trd.push_back(std::thread(&ThreadManager::infiniteLoop, this));
	}

	ThreadManager::~ThreadManager()
	{
		isStopped = true;

		for (int i = 0; i < trd.size(); ++i)
			trd[i].join();
	}

	void ThreadManager::addTask(std::function<void()> task)
	{
		ThreadManager* TM = instance();
		
		while (TM->spinLock.test_and_set()) {}

		TM->taskList.push_back(task);

		TM->spinLock.clear();

		//TM->clock_begin = std::chrono::steady_clock::now();
	}

	void ThreadManager::infiniteLoop()
	{
		while (!isStopped)
		{
			while (spinLock.test_and_set()) {};

			if (!taskList.empty())
			{
				std::function<void()> job = taskList.front();
				taskList.pop_front();
				spinLock.clear();
				job();
			}
			else
			{
				spinLock.clear();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));

				//clock_end = std::chrono::steady_clock::now();
				//auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(clock_end - clock_begin);
			}

		}
	}
}