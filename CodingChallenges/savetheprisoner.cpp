#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



//n: number of prisoners
//m: number of candy
//s: starting chair


//solution that has timeout 
int saveThePrisoner(int n, int m, int s) {
    int candy_number = s;
    int prisoner = s; 
    for(int i = 1; i <= m; i++)
    {
        prisoner = candy_number; 
        candy_number++; 
 
        if(prisoner >= n)
          candy_number = 1;

    }

    return prisoner;
}

//proper solution
int saveThePrisoner(int n, int m, int s, int k) {
    
    int prisoner = (s + m - 1) % n;

    if(prisoner == 0 ) prisoner = n;

    return prisoner;
}
int main() {
    
 

  int n= 5;
  int m= 2;
  int s= 1;

  cout << saveThePrisoner(n,m,s,0) << endl;

  return 0;
}
