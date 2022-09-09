#include <iostream>
#include <vector>
#include <string> 

using namespace std;


class Car{
    int position;
    std::vector<class Observer*> observerList;

    public:
        int getPosition(){
            return position;
        }
        void setPosition(int newPosition){
            position = newPosition;
            notify();
        }
        void attach(Observer* obs){
            observerList.push_back(obs);
        }
        void detach(Observer* obs){
            // observerList.erase(std::remove(observerList.begin(), 
            //                         observerList.end(), obs),observerList.end());
        }
        void notify();
};

class Observer{
    Car *_car;
    public:
        Observer(Car *car){
            _car = car;
            _car->attach(this);
        }
        virtual void update() = 0;
    protected:
        Car *getCar(){
            return _car;
        }

};

void Car::notify(){
    for(int i=0;i<observerList.size();++i){
        observerList[i]->update();
    }
}

class LeftObserver : public Observer{
    public:
    LeftObserver(Car *car) : Observer(car){}
    void update(){
        int pos = getCar()->getPosition();
        std::cout << pos << std::endl;
        if(pos < 0){
            cout << "left side" << endl;
        }
    }
};

class RightObserver : public Observer{
    public:
    RightObserver(Car *car) : Observer(car){}
    void update(){
        int pos = getCar()->getPosition();
        if(pos > 0){
            cout << "right side" << endl;
        }
    }
};

class MiddleObserver : public Observer{
    public:
    MiddleObserver(Car *car) : Observer(car){}
    void update(){
        int pos = getCar()->getPosition();
        if(pos == 0){
            cout << "middle side" << endl;
        }
    }
};

// Driver code 
int main() 
{ 
    Car *car = new Car();

    LeftObserver lefobserver(car);
    RightObserver rightobserver(car);
    MiddleObserver middleobserver(car);

    cout << "hit left right to see, b to close" << endl;

    char pressedButton;
    bool breakLoop = false;

    while(breakLoop == false)
    {
        cin >> pressedButton;
        std::cout << pressedButton << std::endl;
        switch (pressedButton)
        {
            case 108://l for left side
                car->setPosition(-1);
                break;
            case 99://c for center
                car->setPosition(0);
            break;
            case 114://r for right side
                car->setPosition(1);
            break;
            case 98://b for break loop
                breakLoop = true;
            break;

            default:
                cout << "drive carefully" << endl;
                break;
        }
    }
    

    return 0; 
} 