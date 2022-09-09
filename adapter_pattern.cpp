#include <iostream>
#include <unordered_map>
#include <string> 
#include <memory>

using namespace std;

class IndianSocket{
    public:
    virtual void indiancharge(int type) = 0;
};

class USASocket{
    public:
    void usacharge(){
        cout << "USA plug is charging" << endl;
    }
};

class GSocket{
    public: 
    void gcharge(){
        cout << "G plug is charging" << endl;
    }
};

class SocketAdapter : public IndianSocket, public USASocket, public GSocket{
public:
    void indiancharge(int type){
        switch (type)
        {
        case 1:
            usacharge();
            break;
        case 2:
            gcharge();
            break;
        default:
            break;
        }
    }

};

// Driver code 
int main() 
{ 
    unique_ptr<IndianSocket> socket = make_unique<SocketAdapter>();
    socket->indiancharge(1);

    socket->indiancharge(2);

    return 0; 
} 
