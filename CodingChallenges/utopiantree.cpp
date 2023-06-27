#include <iostream>
#include <vector>
#include <algorithm>



int utopianTree(int n) 
{
  
  int height = 1;
  bool toggle = false;
  for(int i=0;i<n;i++)
  {
      toggle = !toggle;
      if(toggle)
      {
        height = height * 2;
      }
      else {
        height++;
      }
  }

  return height;

}

int main()
{

  std::cout << utopianTree(5) << std::endl;

  return 0;
}
