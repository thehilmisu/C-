#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> digits;

void getDigits(int n)
{
   if(n >= 10)
       getDigits(n / 10);

    int digit = n % 10;

    digits.push_back(digit); 
}

int findDigits(int n) 
{
   if (n <= 0)
      return 0;

   getDigits(n);

   int result = 0;
   for(auto i : digits)
       if(i != 0 && (n % i) == 0)
          result++;


  return result;
   
}


int main()
{

  std::cout << findDigits(1012) << std::endl;

  return 0;
}
