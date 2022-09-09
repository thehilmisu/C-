#include <iostream>
#include <string> 

using namespace std;


class GameSetting{
    static GameSetting* _instance;
    int _brightness;
    int _width;
    int _height;
    GameSetting() : _width(750), _height(1200), _brightness(75){}

    public:
        static GameSetting* getInstance(){
            if(_instance == NULL)
                _instance = new GameSetting();
            return _instance;
        }
        void setWidth(int width){ _width = width;}
        void setHeight(int height){ _height = height;}
        void setBrightness(int brightness){_brightness = brightness;}

        int getWidth(){return _width;}
        int getHeight(){return _height;}
        int getBrightness(){return _brightness;}
        void displaySettings(){
            cout << _brightness << endl;
            cout << _width << endl;
            cout << _height << endl;
        }
};

GameSetting * GameSetting::_instance = NULL;

// Driver code 
int main() 
{ 
    
    GameSetting *setting = GameSetting::getInstance();

    setting->displaySettings();

    return 0; 
} 