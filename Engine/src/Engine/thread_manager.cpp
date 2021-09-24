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
		for (int i = 0; i < trd.size(); ++i)
			trd[i].join();
	}

	void ThreadManager::addTask(std::function<void()> task)
	{
		while (spinLock.test_and_set()) {}

		taskList.push_back(task);

		spinLock.clear();
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
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	}
}