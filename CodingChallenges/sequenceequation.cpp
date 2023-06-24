#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> permutationEquation(std::vector<int> p) {
  
  int n = p.size();

  std::vector<int> x ;
  std::vector<int> y ;
  std::vector<int> res;

  //initialize x with 1 ... n
  for(int i=1; i<=n;i++)
    x.push_back(i);

  for(int k=1;k<=n;k++)
  {
    for(int j=1;j<=n;j++)
      if(x.at(k-1) == p.at(j-1) )
        y.push_back(j);
  }

  for(int k=1;k<=n;k++)
  {
    for(int j=1;j<=n;j++)
      if(y.at(k-1) == p.at(j-1) )
        res.push_back(j);
  }

  return res;

}

int main()
{
  
  std::vector<int> p = {5, 2, 1, 3, 4};

  for(auto i : permutationEquation(p))
    std::cout << i << std::endl;

  return 0;
}
