//https://www.codingninjas.com/codestudio/problems/minimum-subarray-with-required-sum_696460?topList=top-fintech-software-engineer-interview-questions/


#include <cmath
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Recursive function to print all possible subarrays for
// given array
//

vector<vector<int>> subArrays;

vector<vector<int>> possibleSubArrays(vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return subArrays;
    // Increment the end point and start from 0
    else if (start > end)
        possibleSubArrays(arr, 0, end + 1);
    // Print the subarray and increment the starting point
    else {
        vector<int> temp;
        for (int i = start; i < end; i++)
          temp.push_back(arr.at(i));

        temp.push_back(arr.at(end));
        subArrays.push_back(temp);
        possibleSubArrays(arr, start + 1, end);
    }
    return subArrays;
}

vector<int> minSubarray(vector<int> arr, int n, int x)
{
  vector<vector<int>> result;
  vector<vector<int>> test = possibleSubArrays(arr, 0 , 0);

  for(int i=0;i<test.size();i++)
  {
    int sum = 0;
    for(int j=0;j<test.at(i).size();j++)
    {
       sum += test.at(i).at(j);
    }
    if(sum > x && test.at(i).size() == 2)
      result.push_back(test.at(i));

  }

  std::sort(result.begin(), result.end());

  return result.at(0);
}


int main() {

  vector<int> input = {1,1,2,2,4,4,5,5,5}; 
  
  int n = 10;
  int x = 5;

  //cout << minSubarray(input, n, x) << endl;
  vector<int> a = minSubarray(input, 0, 5);
  for(int i=0;i<a.size();i++)
  {
    cout << a.at(i) << "," ;
    cout << endl;
  }

  return 0;
}
