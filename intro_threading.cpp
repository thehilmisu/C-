#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)


// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.

// NOTES:
// Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will 
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for(ull i=start;i<=end;i++){
        if((i & 1) == 0){
            EvenSum += i;
        }
    }
}

void findOdd(ull start, ull end)
{
    for(ull i=start;i<=end;i++){
        if((i & 1) == 1){
            OddSum += i;
        }
    }
}

int main()
{

    ull start =0, end = 1900000000;

    auto startTime = high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();//you have to join to main thread
    t2.join();

    // findOdd(start,end);
    // findEven(start, end);

    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum :" << OddSum << endl;
    cout << "EvenSum :" << EvenSum << endl;

    cout << "duration :" << duration.count()/1000000 << " seconds" << endl;

    return 0;
}