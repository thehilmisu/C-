
#include <iostream>
#include <vector>

bool isEven(int n)
{
  return ( n % 2 == 0);
}

void sumOfPairs(vector<int> arr)
{
    int n = arr.size(); 

  std::vector<std::pair<std::vector<int>, int>> sumOfPairs; // Vector to store the sums of pairs

    // Iterate through the array and find all possible subarrays of size 2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr.at(i) + arr.at(j);
      sumOfPairs.push_back(sum);
        }
    }

    // Display the sums of pairs
    for (int sum : sumOfPairs) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> subArrays;

std::vector<std::vector<int>> possibleSubArrays(std::vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return subArrays;
    // Increment the end point and start from 0
    else if (start > end)
        possibleSubArrays(arr, 0, end + 1);
    // Print the subarray and increment the starting point
    else {
    std::vector<int> temp;
        for (int i = start; i < end; i++)
          temp.push_back(arr.at(i));

        temp.push_back(arr.at(end));
        subArrays.push_back(temp);
        possibleSubArrays(arr, start + 1, end);
    }
    return subArrays;
}

int nonDivisibleSubset(int k, std::vector<int> s) 
{
   
  for(auto i : possibleSubArrays(s,0,0))
  {
    for(auto j : i)
    {
      if(k % j != 0 )
      {

      }
      else 
      {
          
      }
    }

  }
  return 0;

}

int main()
{

  std::vector<int> temp = { 19,10,12,10,24,25,22 };
  int k = 4;

  std::cout << nonDivisibleSubset(k, temp) << std::endl;


  return 0;
}
