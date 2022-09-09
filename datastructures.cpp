#include <iostream>
#include <vector>

using namespace std;

class LinkedList
{
    private:
    struct node{
        node *prev;
        node *next;
        int value;
    };
    vector<node> nodes;
    public:
        LinkedList();
        int addListItem();
        bool addListItem(int index);
        bool removeListItem(int index);



    
};

int main(){

    cout << "Run successfully" << endl;
    return 0;
}