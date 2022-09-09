#ifndef PRODUCER_H
#define PRODUCER_H



#include <iomanip>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include "pool.h"
#include "thread.h"
#include <list>

#include "pcap.h"

using namespace std;

class Producer : public Thread
{
private:
    string _path;
    Pool<vector<u_char>> * _pool;
protected:
    virtual void run();

public:
    Producer(string path, Pool<vector<u_char>> * pool);
    void readPacket();



};
#endif // PRODUCER_H
