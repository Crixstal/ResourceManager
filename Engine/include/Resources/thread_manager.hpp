#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <queue>
#include <functional>
#include <chrono>

namespace Resources
{
	class ThreadManager
	{
		private:
			int maxThread = std::thread::hardware_concurrency();

			std::vector<std::thread> trd;

			std::queue<std::function<void()>> taskList;

			std::function<void()> job;

			std::atomic_flag lock = ATOMIC_FLAG_INIT;

			std::atomic<bool> dataReady{false};

		public:
			ThreadManager();
			~ThreadManager();

			void addTask(std::function<void()> task);
			void infiniteLoop();
	};
}