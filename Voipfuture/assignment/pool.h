#ifndef __POOL_H__
#define __POOL_H__

#include <queue>
#include <mutex>
#include <iostream>
#include <unistd.h>

using namespace std;


/**
  * @brief Template pool class for general purpose usage
  *
  * thread safe pop, push and get size functions
  *
  * @param maximum packet count, thread sleep variable
  *
  */
template <class T> class Pool
{
private:
    std::queue<T> data;
    std::mutex mtx;
    size_t max_size;
    size_t spin_time;
public:
    Pool(size_t max_size = 1000, size_t spin_time = 50)
        : max_size(max_size), spin_time(spin_time)
    {}
    ~Pool()
    {
        mtx.lock();
        while (data.size()) data.pop();
        mtx.unlock();
    }
    size_t size()
    {
        mtx.lock();
        size_t result = data.size();
        mtx.unlock();
        return result;
    }
    void push(T item)
    {
        mtx.lock();
        if (data.size() < max_size)
        {
           data.push(item);
        }
        mtx.unlock();
    }
    T pop()
    {
        mtx.lock();
        T item;
        if(data.size() > 0)
        {
            item = data.front();
            data.pop();
        }
        mtx.unlock();
        return item;
    }
};

#endif
