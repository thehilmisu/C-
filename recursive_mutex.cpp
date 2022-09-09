#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::recursive_mutex m1;
int buffer = 0;


//example 1: recrusion
void recursion(char c, int loopFor){
    if(loopFor<0)
        return;

    m1.lock();
    cout << c << " " << buffer++ << endl;
    recursion(c, --loopFor);
    m1.unlock();
}

int main(){

    thread t1(recursion, '0', 10);
    thread t2(recursion, '1', 10);

    t1.join();
    t2.join();

    return 0;
}