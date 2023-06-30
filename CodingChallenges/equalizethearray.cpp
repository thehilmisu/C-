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

int equalizeArray(vector<int> arr) {
  
  int element_count = findMostOccuringElement(arr);
  int count = arr.size() - element_count;

  return count;
}


int main()
{
  vector<int> a = {3,3,2,1,3};

  std::cout << equalizeArray(a) << std::endl; 

  return 0;
}
