#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int findMostOccuringElement(vector<int> arr)
{
  map<int, int> m;
  for(auto i : arr)
    m[i]++;

  std::map<int,int>::iterator best
        = std::max_element(m.begin(),m.end(),[] (const std::pair<int,int>& a, const std::pair<int,int>& b)->bool{ return a.second < b.second; } ); 
  
  //std::cout << best->first << " : " << best->second << std::endl;   

  return best->second;
}

int minimumDistances(vector<int> a) {
  

}


int main()
{


  return 0;
}
