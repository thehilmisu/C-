#include <iomanip>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <unordered_map>
#include <vector>
#include <list>

#include "pcap.h"

using namespace std;

// #####################################################################################################################
// #####################################################################################################################

/**
  * @brief ipStatistic
  *
  * Collect statistical information per source ip address
  *
  * <key>   IPv4 or IPv6 address
  * <value> The amount of packets sent by a host
  */
unordered_map<string, int32_t> IpStatistic;

/**
  * @brief PacketBuffer
  *
  * Container to store packets
  */
typedef list<vector<u_char>> packet_buffer;
packet_buffer PacketBuffer;

// #####################################################################################################################
// #####################################################################################################################

/**
  * @brief Account packets per endpoint
  *
  * This method will acount the number of packets per endpoint. Finally it will release the memory of allocated
  * packets.
  *
  * @param packetBuffer    A reference to packet buffer to be processed.
  *
  */
void accountPacketsPerEndpoint(packet_buffer &packetBuffer)
{
  for (const auto &packet : packetBuffer) {
    auto ethernetHeader = reinterpret_cast<const struct ether_header *>(packet.data());
    if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP) {
      auto ipHeader = reinterpret_cast<const struct ip *>(packet.data() + sizeof(struct ether_header));

      char buffer[INET6_ADDRSTRLEN];

      inet_ntop(AF_INET, &(ipHeader->ip_src), buffer, INET_ADDRSTRLEN);
      string sourceIp(buffer);

      inet_ntop(AF_INET, &(ipHeader->ip_dst), buffer, INET_ADDRSTRLEN);
      string destIp(buffer);

      ++IpStatistic[sourceIp];
    }
  }
  packetBuffer.clear();
}

// #####################################################################################################################
// #####################################################################################################################

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
  cerr << "Usage: " << applicationName << " [capture_file]" << endl << endl;
  exit(1);
}

// #####################################################################################################################
// #####################################################################################################################

int main(int argc, char *argv[])
{
  char pcapErrorBuffer[PCAP_ERRBUF_SIZE];

  static constexpr uint8_t ColumnWidth {20};

  // Check the number of parameters
  if (argc < 2) {
    usage(argv[0]);
  }

  string captureFile(argv[1]);
  struct stat buffer;
  if (stat(captureFile.c_str(), &buffer) != 0) {
    cerr << "ERROR: File '" << captureFile << "'does not exists." << endl
         << "       Please provide a valid capture file." << endl;
    return 2;
  }

  // Clear the error buffer
  memset(pcapErrorBuffer, 0, PCAP_ERRBUF_SIZE);

  // Open the capture file for offline parsing
  auto pcapHandle = pcap_open_offline(captureFile.c_str(), pcapErrorBuffer);
  if (pcapHandle == nullptr) {
    cerr << "ERROR: pcap_open_offline() failed." << endl;
    cerr << "       " << pcapErrorBuffer << endl;
    return 3;
  }

  // The pcap header structure
  struct pcap_pkthdr packetHeader;

  const u_char *packet;

  while (1) {

    // Get next packet from capture file
    packet = pcap_next(pcapHandle, &packetHeader);
    
	if (((PacketBuffer.size() % 1000) == 0)
        || packet == nullptr) {
      accountPacketsPerEndpoint(PacketBuffer);
    }

    if (packet == nullptr) {
      // we are done, eof reached
      break;
    }

    vector<u_char> p(packet, packet + packetHeader.len);
    PacketBuffer.push_back(p);
  }

  // Close the pcap file handle
  pcap_close(pcapHandle);

  cout << endl
       << "All packets of '" << captureFile << "' are parsed" << endl
       << endl;

  // Print a statistic
  cout << setw(ColumnWidth) << right << " ip address"
       << " | "
       << setw(ColumnWidth) << right << " # of packet(s)" << endl;

  for (const auto &stat: IpStatistic) {
    cout << setw(ColumnWidth) << stat.first << " | "
         << setw(ColumnWidth) << right << stat.second << endl;
  }

  return 0;
}
