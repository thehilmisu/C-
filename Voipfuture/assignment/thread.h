#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
/**
  * @brief thread class
  *
  * thread class to use posix thread
  *
  */
class Thread
{
	private:
		pthread_t thread;
		static void * dispatch(void *);
	protected:
		virtual void run() = 0;
	public:
		virtual ~Thread();
		void start();
		void join();
};

#endif
