#include <iostream>

#include <vector>



using namespace std;

int getTotalX(vector<int> a, vector<int> b) {

    
  int ans=0;
  for(int x=1;x<=100;x++){
      bool ok=true;
      for(int i=0;i<a.size();i++) if(x%a.at(i)!=0) ok=false;
      for(int i=0;i<b.size();i++) if(b.at(i)%x!=0) ok=false; 
      if(ok) ans++;
  } 

    return ans;
}

int main()
{
  vector<int> a = {2,6};
  vector<int> b = {24,36};

  //getTotalX(a,b);
  cout << getTotalX(a,b) << endl;

  return 0;
}
