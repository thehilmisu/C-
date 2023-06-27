#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

//time limit exception on some of the test cases
int __squares(int a, int b) 
{

    int count = 0;
    for(int i=a; i<=b; i++)
    {
        int sq = sqrt(i);
        if((sq * sq) == i)
          count++;
    }


    return count;
}

//proper solution
int squares(int a, int b) 
{
    int sr = sqrt(a);
    int count = 0;
    while ((sr * sr) <= b)
    {
        if ((sr * sr) >= a)
            count++;
        sr++;
    }
    return count;
}


int main()
{
  std::cout << squares(24,49) << std::endl;

  return 0;
}
