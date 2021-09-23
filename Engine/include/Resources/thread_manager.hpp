#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <deque>
#include <functional>
#include <chrono>

#include "singleton.hpp"

class Texture;

namespace Core::Engine
{
	class ThreadManager
	{
		private:
			int maxThread = std::thread::hardware_concurrency();

			std::vector<std::thread> trd;

			std::deque<std::function<void()>> taskList;

			std::atomic_flag spinLock = ATOMIC_FLAG_INIT;

		public:
			std::atomic<bool> isStopped{false};

			ThreadManager();
			~ThreadManager();

			void addTask(std::function<void()> task);
			void infiniteLoop();
	};
}