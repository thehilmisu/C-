#include <iostream>
#include <vector>
#include <algorithm>

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {

    int fine = 0;


    if(d1 - d2 > 0 )
    {  

      if(m1 == m2 && y1 == y2 )
      {
        fine = (d1 - d2) * 15;
      }
    
    }
    
    if( m1 - m2 > 0 && y1 == y2)
    {
      fine = 500 * (m1 - m2);
    }

    if( y1 - y2 > 0)
    {  
      fine = 10000;
    }
  


    return fine;

}


int main()
{
  
  std::cout << libraryFine(9, 6, 2015, 6, 6, 2015 ) << std::endl;

  return 0;
}
