#ifndef CONSUMER_H
#define CONSUMER_H

#include "pool.h"
#include "logger.h"
#include "thread.h"
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <unordered_map>

#include "pcap.h"



using namespace std;

class Consumer : public Thread
{

private:
    Pool<vector<u_char>> * _pool;
    Logger* _log;
    /**
      * @brief ipStatistic
      *
      * Collect statistical information per source ip address
      *
      * <key>   IPv4 or IPv6 address
      * <value> The amount of packets sent by a host
      */
    unordered_map<string, PacketInfo> IpStatistic;
    void readPacketFromQueue(vector<u_char> packet);
    void updateStatistics();
    void parsePacket(vector<u_char> packet);


protected:
    virtual void run();
public:
    Consumer(Pool<vector<u_char>> * pool, Logger* log);
};

#endif // CONSUMER_H
