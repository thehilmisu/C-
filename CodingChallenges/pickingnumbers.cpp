#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pickingNumbers(vector<int> a) {

  vector<int> subArr;

  int ans=0;

  int pivot = 0;
  for(int i=1;i<a.size();i++)
  {
    ans = max(ans, a.at(i-1) + a.at(i));
  }


  return ans;
}

int main() {
    
 

  
  vector<int> input = {1,1,2,2,4,4,5,5,5}; 

  cout << pickingNumbers(input) << endl;

  return 0;
}
