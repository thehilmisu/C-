#include "logger.h"

/**
  * @brief Logger class constructor
  *
  * Called when object is created
  * initialiazes variable
  *
  * @param consumerCount: thread count
  */
Logger::Logger(int32_t consumerCount)
{
    _consumerCount = consumerCount;
    finishedJobCount = 0;
}

/**
  * @brief Logger class deconstructor
  *
  * called when object is destroyed
  * clearing statictics to free memory
  */
Logger::~Logger(){
    mute.lock();
    if (_statistics.size() > 0) _statistics.clear();
    mute.unlock();
}

/**
  * @brief Logger
  *
  * This method is adding log string to the log list which will be printed out
  *
  * @param text: log string
  */
void Logger::log(unordered_map<string, PacketInfo> statistics)
{
    mute.lock();

    for (const auto &stat: statistics) {
        _statistics[stat.first].packet_count += stat.second.packet_count;
        _statistics[stat.first].packet_size += stat.second.packet_size;
        for(auto &i:stat.second.destinationIP)
            _statistics[stat.first].destinationIP.insert(i);
    }
    finishedJobCount++;

    mute.unlock();

    //every thread has finished, print statistics
    if(finishedJobCount == _consumerCount)
        print();
}

/**
  * @brief print
  *
  * This method is printing statistics
  * IP address, packet count, packet size, destination IP's
  *
  */
void Logger::print()
{
    cout << setw(35) << right << "Statistics" << endl;

    cout << setw(15) << right << "IP address" << setw(20) << right << "packet count"
         << setw(20) << right << setw(20) << right  << "packet size"
         << setw(25) << right  << "destination addresses" <<endl;

    for (const auto &stat: _statistics) {
        cout << setw(15) << right << stat.first << setw(20) << right << stat.second.packet_count
             << setw(20) << right << setw(20) << right  << stat.second.packet_size << setw(20) << right
             ;
        for(auto &i:stat.second.destinationIP)
            cout << i << ",";

        cout << endl;
    }
}
