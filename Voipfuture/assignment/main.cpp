
#include <vector>

#include "producer.h"
#include "consumer.h"
#include "logger.h"

using namespace std;

/**
  * @brief The usage
  *
  * This method is printing the usage to consol end quits the application with exit code 1
  *
  * @param applicationName the name of application to be used in print out
  */
void usage(string applicationName)
{
  cerr << "This program is capable to parse a given capture file." << endl << endl;
  cerr << "Usage: "
  << applicationName
  << " [capture_file]"
  << " [thread_count]"
  << " [max_packet_size]"
  << endl << endl;
  exit(1);
}

int main(int argc, char *argv[])
{

    // Check the number of parameters
    if (argc < 4) {
      usage(argv[0]);
    }

    vector<Consumer *> consumers;

    //clear initially
    consumers.clear();

    int32_t consumerCount = atoi(argv[2]);
    int32_t packetCount = atoi(argv[3]);

    Pool<vector<u_char>> * pool = new Pool<vector<u_char>>(packetCount,10);
    Logger*  logg  = new Logger(consumerCount);

    Producer p(argv[1], pool);
    p.readPacket();
    p.join();

    //Create consumer threads, start and join them accordingly
    for(int i=0;i<consumerCount;i++){
        consumers.push_back(new Consumer(pool, logg));
        consumers[i]->start();
        consumers[i]->join();
    }

    //delete logg object
    delete logg;


    return 0;
}
