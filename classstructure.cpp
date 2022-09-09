
#include <iostream>
#include <vector>
using namespace std;

class Shape {
    public:
        Shape(){
            cout << "Shape constructor called!" <<endl; 
        }
        ~Shape(){
            cout << "Shape Deconstructor" << endl;
        }
        virtual int area(int a,int b){
            return a+b;
        }
        int test(){
            return privateTest;
        }
    private:
        int privateTest = -1;
};

class Box : public Shape {
   public:
      Box() { 
         cout << "Box constructor called!" << endl; 
      }
      ~Box(){
            cout << "Box Deconstructor" << endl;
        }
      int area(int a, int b){
          return a*b;
      }
      int area(int a){
          return a;
      }
      
};

int main(){

    Shape s;

    cout << "-------------" << endl;

    Box b;

    cout << "-------------" << endl;

    Shape *sb = new Box();

    cout << "-------------" << endl;


    return 0;
}