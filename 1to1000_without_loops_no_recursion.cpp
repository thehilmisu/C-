#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

class A 
{ 
public: 
    static int a; 
    A() {  cout<<a++<<endl;  } 
}; 
  
int A::a = 1; 

int main() {
  
  A nesne[100];
  
  return 0;
}