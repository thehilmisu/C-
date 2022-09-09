//union variables share common memory for all its elements

//a[b] means *(a+b) by C standard. a is base address, b is an offset starting from a.
//a[b] is the value in the address of a+b.
//Thus a+5 and 5+a is the same memory address. Their value *(a+5) and *(5+a) is the same. 
//So a[5] == 5[a]

//int* arr1[8];
//int (*arr2)[8];
//int *(arr3[8]);

// For int* arr1[8]
// arr1 first and foremost is an array no matter what type the element is. 
// After applying pointer *, we know arr1 is an array of int pointers.

// For int (*arr2)[8]
// By bracket overriding rule, pointer * has higher precedence over array [] in this case.
// Then arr2 is first and foremost a pointer no matter what it is pointing to. After applying array [], 
// we know arr2 is a pointer to an array of int.

// For int *(arr3[8])
// Bracket in this case does not change any default precedence, so it is the same as int* arr1[8]

//alex.shirley@egym.com interview guy, ask anything if you have more questions

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

// Shape* getShape(){
    
//     Shape s;
    
//     return &s;
// }

vector<int> removeDuplicates(vector<int> v)
{
    vector<int> c;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            int res = v.at(j) ^ v.at(i);//c.push_back(t.at(j) ^ v.at(i) );
            if(res == 0){
                //v.erase(v.begin()+i);
                cout << i << endl;
            }
                
        }
    }
    
    return c;
}

int main() {
    
    
  vector<int> v = {0,1,2,2,3,4,4,5};
  
  vector<int> test = removeDuplicates(v); 
  
//   for(int i : test)
//   {
//       cout << i << endl;
//   }
    
  // Box* myBoxArray = new Box[4];
  // delete [] myBoxArray; // Delete array
  
  //Box* b = new Shape();
//   Box* b = new Box();
//   Shape* s = new Shape();
  
//   cout << b->area(3,5) << endl;
//   cout << s->area(3,5) << endl;
//   cout << b->test() << endl;
//   cout << b->area(28) << endl;
  
//   delete b;
  
  Shape* d = new Box();

  delete d;
  
//   cout << d->area(3,2) << endl;
  
//   Shape *shp = getShape();
//   shp->test();

   return 0;
}
