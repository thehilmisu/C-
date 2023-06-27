#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>


using namespace  std; 
  

string __appendAndDelete(string s, string t, int k) {
    
  if( (s.size() == t.size()) && (s.size() + t.size()) <= k)
    return "Yes";

  
  if(s.size() > t.size())
  {
    if( (s.size() - t.size()) > k )
      return "No";
  }
  else
  {
    if( (t.size() - s.size()) > k )
      return "No";
  }



  return "Yes"; 

}

string appendAndDelete(string s, string t, int k)
{
    int i = 0;
    for ( ; i < std::min(s.length(),t.length()); ++i) {
        if (s[i] != t[i]) {
            break;
        }
    }
    
    int min_ops = (t.length()-i) + (s.length()-i);
    
    int more_ops = min_ops;
    while(more_ops < k) {
        if (i-- > 0)
            more_ops += 2;
        else
            more_ops++;
    }

    return (more_ops == k ? "Yes" : "No");
}

int main()
{
  
  std::cout << appendAndDelete("ashley","ash", 2)  << std::endl;


  return 0;
}
