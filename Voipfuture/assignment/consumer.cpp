#include "consumer.h"


/**
  * @brief Consumer constructor
  *
  * constructor, initializes variables
  *
  * @param pool object pointer, logger pointer
  *
  */
Consumer::Consumer(Pool<vector<u_char>> * pool, Logger* log)
{
    _pool = pool;
    _log = log;
}
/**
  * @brief Account packets per endpoint
  *
  * This method will acount the number of packets per endpoint. Finally it will release the memory of allocated
  * packets.
  *
  * @param packet   A reference to packet to be processed.
  *
  */
void Consumer::readPacketFromQueue(vector<u_char> packet)
{
    parsePacket(packet);
}
/**
  * @brief Packet parser
  *
  * parses the packet and filling the ipstatistics
  *
  * @param packet
  *
  */
void Consumer::parsePacket(vector<u_char> packet)
{
    auto ethernetHeader = reinterpret_cast<const struct ether_header *>(packet.data());
    if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) {
      auto ipHeader = reinterpret_cast<const struct ip *>(packet.data() + sizeof(struct ether_header));

//      auto tcpHeader = reinterpret_cast<const struct tcphdr *>(packet.data() + sizeof(struct ether_header) + sizeof(struct ip));


//      if(ipHeader->ip_p == IPPROTO_TCP){


//      }else if(ipHeader->ip_p == IPPROTO_IP){


//      }else if(ipHeader->ip_p == IPPROTO_UDP){

//      }

      char buffer[INET6_ADDRSTRLEN];

      inet_ntop(AF_INET, &(ipHeader->ip_src), buffer, INET_ADDRSTRLEN);
      string sourceIp(buffer);

      inet_ntop(AF_INET, &(ipHeader->ip_dst), buffer, INET_ADDRSTRLEN);
      string destIp(buffer);


      ++IpStatistic[sourceIp].packet_count;
      IpStatistic[sourceIp].packet_size += ipHeader->ip_len;
      IpStatistic[sourceIp].destinationIP.insert(destIp);
    }
}

void Consumer::updateStatistics(){
    _log->log(IpStatistic);
}
/**
  * @brief thread run
  *
  * thread's eternal loop
  * read packets from pool and updates statisctics when it's done
  *
  */
void Consumer::run(){

    while(1){
        if(_pool->size() > 0 ){
            readPacketFromQueue(_pool->pop());
        }else{
            updateStatistics();
            break;
        }
    }

}
