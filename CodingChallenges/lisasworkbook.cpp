#include <iostream>
#include <vector>
#include <algorithm>


int workbook(int n, int k, std::vector<int> arr) {
    
    int numProblems, specialProblems = 0, pageNumber = 0;
    for(int i = 0; i < n; i++) {
        numProblems = arr.at(i);
        pageNumber++; // increase for new chapter
        int problem = 1;
        while(numProblems > 0) {
            numProblems--;
            if(problem == pageNumber) {
                specialProblems++;
            }
            if(problem%k == 0 && numProblems != 0) {
                pageNumber++; // increase for full page
            }
            problem++;
         }
    }
    
    return specialProblems;
}


int main()
{

  int n = 5, k = 3;
  std::vector<int> arr = {4, 2, 6, 1, 10};

  std::cout << workbook(n,k,arr) << std::endl;


  return 0;
}
