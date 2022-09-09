#ifndef LOGGER_H
#define LOGGER_H

#include <iomanip>
#include <iostream>
#include <set>
#include <mutex>
#include <string>
#include <unordered_map>


using namespace std;

struct PacketInfo{
    int32_t packet_count;
    int32_t packet_size;
    set<string> destinationIP;
};


class Logger
{
private:
    mutex mute;
    unordered_map<string, PacketInfo> _statistics;
    int32_t _consumerCount;
    int32_t finishedJobCount;
public:
    Logger(int32_t consumerCount);
    ~Logger();
    void log(unordered_map<string, PacketInfo> statistics);
    void print();
};

#endif // LOGGER_H


