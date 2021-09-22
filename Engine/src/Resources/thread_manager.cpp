#include "thread_manager.hpp"

namespace Resources
{
	ThreadManager::ThreadManager()
	{
		for (int i = 0; i < maxThread; i++)
			trd.push_back(std::thread(&infiniteLoop, this));
	}

	ThreadManager::~ThreadManager()
	{
		
	}

	void ThreadManager::addTask(std::function<void()> task)
	{
		while (true)
		{
			while (lock.test_and_set());

			taskList.push(task);

			lock.clear();
		}
	}

	void ThreadManager::infiniteLoop()
	{
		while (true)
		{
			//while (lock.test_and_set())
			while (!dataReady.load())
				std::this_thread::sleep_for(std::chrono::milliseconds(10));

			//if (taskList.empty())
				//atomic_flag_wait(lock);
				//varCondition.wait(lock);

			for (int i = 0; i < taskList.size(); ++i)
			{
				if (!taskList.empty())
					job = taskList[i];
				else
					std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //value to determine
			}

			dataReady = true;
			//lock.clear();

			job();
		}
	}
}