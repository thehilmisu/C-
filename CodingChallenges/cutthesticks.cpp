#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


vector<int> cutTheSticks(vector<int> arr) {

  
    sort(arr.begin(), arr.end());

    unordered_set<int> sticks;
    for(int i=0;i<arr.size();i++)
    { 
      int iteration =0;
      int shortest = arr.at(i);
      //std::cout << "shortest : " << shortest << std::endl;
      for(int k=0;k<arr.size(); k++)
      {
          int cut = arr.at(k) - shortest;
          //std::cout << "cut : " << cut  << std::endl;
          if(cut >= 0 )
            iteration++;
      }

      sticks.insert(iteration);

    }

    vector<int> res;
    for(auto i : sticks)
      res.push_back(i);



    sort(res.begin(), res.end(), greater<int>());

  return res;

}


int main()
{

  vector<int> arr = {5, 4, 4, 2, 2, 8};

  for( auto i : cutTheSticks(arr))
    std::cout << i << std::endl;

  return 0;
}
