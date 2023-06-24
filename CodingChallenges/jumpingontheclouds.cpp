#include <iostream>
#include <vector>
#include <algorithm>

int jumpingOnClouds(std::vector<int> c, int k) {

  int energy_level = 100;
  int n = c.size();
  int index = 0;

  std::cout << k << std::endl;
  //I should use while loop in there
  for(int i=0;i<n+200;i=i+k)
  {

    int cloud = c.at(index);
    std::cout << "index: " << index << " cloud: " << cloud << std::endl; 
    index = ((i + k)%n);
  
   
    if(cloud == 1)
      energy_level = energy_level - 3;
    else
      energy_level--;

    if(index == 0)
      break;


  }

  return energy_level;
}


int main()
{
  //1 1 1 0 1 1 0 0 0 0
  std::vector<int> c = {1, 1, 1, 0, 1, 1, 0, 0, 0, 0};
  int k=3;

  std::cout << jumpingOnClouds(c, k) << std::endl;

  return 0;
}
