
#ifndef __WD_THREADPOOL_H__
#define __WD_THREADPOOL_H__

#include "TaskQueue.h"
#include <vector>
#include <memory>
#include <functional>
using std::unique_ptr;
using std::vector;

namespace wd
{

	class Thread;
	class Threadpool
	{
	public:
		typedef std::function<void()> Task;
		Threadpool(size_t, size_t);
		~Threadpool();

		void start();
		void stop();
		void addTask(Task &&task);

	private:
		Task getTask();
		void threadFunc();

	private:
		size_t _threadNumber;
		size_t _queSize;
		vector<unique_ptr<Thread>> _threads;
		TaskQueue _taskque;
		bool _isExit;
	};

} // end of namespace wd

#endif
