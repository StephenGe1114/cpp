 ///
 /// @file    Thread.h
 /// @author  gsw(1499186594@qq.com)
 ///
   

#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

#include <functional>

namespace wd
{

	class Thread
		: Noncopyable
	{
	public:
		using ThreadCallback = std::function<void()>;

		Thread(ThreadCallback &&cb);

		~Thread();

		void start();
		void join();

		pthread_t getThreadId() const { return _pthid; }

	private:
		static void *threadFunc(void *arg);

	private:
		pthread_t _pthid;
		ThreadCallback _cb;
		bool _isRunning;
	};

} // end of namespace wd

#endif

