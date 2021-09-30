#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <deque>
#include <functional>
#include <chrono>

#include "singleton.hpp"

namespace Core::Engine
{
	class ThreadManager final : public Singleton<ThreadManager>
	{
		friend Singleton<ThreadManager>;

		private:
			int maxThread = std::thread::hardware_concurrency();

			std::deque<std::function<void()>> taskList;

			std::atomic_flag spinLock = ATOMIC_FLAG_INIT;

		public:
			std::vector<std::thread> trd;

			std::atomic<bool> isStopped{false};

			ThreadManager();
			~ThreadManager();

			static void addTask(std::function<void()> task);
			static void stop();
			void infiniteLoop();
	};
}