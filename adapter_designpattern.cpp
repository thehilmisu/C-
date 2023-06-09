#include <iostream>
#include <unordered_map>
#include <string> 
#include <memory>

using namespace std;

class IndianSocket{
    public:
    virtual void indiancharge() = 0;
};

class USASocket{
    public:
    void usacharge(){
        cout << "USA plug is charging" << endl;
    }
};

class SocketAdapter : public IndianSocket, public USASocket{
public:
    void indiancharge(){
        usacharge();
    }

};

// Driver code 
int main() 
{ 
    unique_ptr<IndianSocket> socket = make_unique<SocketAdapter>();
    socket->indiancharge();

    return 0; 
} 