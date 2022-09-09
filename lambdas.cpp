#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class Entity {
public:
    Entity()
    {
        cout << "Creaated Entity" << endl;
    }
    ~Entity()
    {
        cout << "Destroyed Entity" << endl;
    }

};

void ForEach(const std::vector<int> values, void(*func)(int)){
    for (int value : values)
        func(value);
}

int main(){

    //whenever you have function pointer, you can use a lambda

    std::vector<int> values = {1, 5, 4, 2, 3};

    ForEach(values, [](int value) { std::cout << "value: " << value << std::endl; });


    auto it = std::find_if(values.begin(), values.end(), [](int value){ return value > 3; });

    std::cout << *it << std::endl;

    // simple lambda function to roll a dice
    auto roll = [](){ return rand() % 6 + 1; };

    return 0;
}