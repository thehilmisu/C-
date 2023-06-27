#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int viralAdvertising(int n) 
{

  int likes = 0;
  int receipents = 5;
  for(int i=1;i<=n;i++)
  {
      likes += floor(receipents / 2);

      receipents = floor(receipents / 2) * 3;
  }

  return likes;

}


int main()
{
  std::cout << viralAdvertising(3) << std::endl;

  return 0;
}
