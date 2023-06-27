#include <iostream>
#include <vector>
#include <algorithm>


int reversed(int n)
{
  int reverse=0, rem;    
  while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;    
  }    
  /* std::cout<<"Reversed Number: "<< reverse << std::endl;      */

  return reverse;
}

int beautifulDays(int i, int j, int k) {
  
   int bdays = 0;
   
   for(int a = i; a <= j; a++)
   {
      if( ( std::abs(a - reversed(a)) % k == 0 ))
          bdays++;

   }

   return bdays;
}

int main()
{
  std::cout << beautifulDays(13, 45, 3) << std::endl;
  //reversed(123);

  return 0;
}
