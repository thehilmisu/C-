#include "producer.h"

Producer::Producer(string path, Pool<vector<u_char>> * pool)
{
    _path = path;
    _pool = pool;
}
/**
  * @brief thread run
  *
  * thread's eternal loop
  * reads and pushes the data from pcap file
  *
  */
void Producer::run(){
    char pcapErrorBuffer[PCAP_ERRBUF_SIZE];

    string captureFile(_path);
    struct stat buffer;
    if (stat(captureFile.c_str(), &buffer) != 0) {
      cerr << "ERROR: File '" << captureFile << "'does not exists." << endl
           << "       Please provide a valid capture file." << endl;
      return;
    }

    // Clear the error buffer
    memset(pcapErrorBuffer, 0, PCAP_ERRBUF_SIZE);

    // Open the capture file for offline parsing
    auto pcapHandle = pcap_open_offline(captureFile.c_str(), pcapErrorBuffer);
    if (pcapHandle == nullptr) {
      cerr << "ERROR: pcap_open_offline() failed." << endl;
      cerr << "       " << pcapErrorBuffer << endl;
      return;
    }

    // The pcap header structure
    struct pcap_pkthdr packetHeader;

    const u_char *packet;

    while (1) {

      // Get next packet from capture file
      packet = pcap_next(pcapHandle, &packetHeader);

      //cout << packet << endl;
      if (packet == nullptr) {
        // we are done, eof reached
        break;
      }

      vector<u_char> p(packet, packet + packetHeader.len);
      _pool->push(p);
      usleep(10);
    }

    // Close the pcap file handle
    pcap_close(pcapHandle);
}

void Producer::readPacket(){
    start();
}
