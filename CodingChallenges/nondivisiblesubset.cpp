
#include <iostream>
#include <vector>
#include <set>

bool isEven(int n)
{
  return ( n % 2 == 0);
}

int sumOfElements(std::vector<int> arr)
{
  int sum = 0;
  
  for(auto i : arr)
    sum = sum + i;

  return sum;
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

void sumOfPairs(std::vector<int> arr)
{

    std::vector<std::pair<int, int>> sumOfPairs; // Vector to store the sums of pairs

    std::vector<std::vector<int>> subArrays = possibleSubArrays(arr, 0, 0);
    int n = subArrays.size();  
    for (int i = 0; i < n; i++) 
    {
       int sum = sumOfElements(subArrays.at(i));
       sumOfPairs.push_back(std::make_pair(i, sum));
    }

    // Display the sums of pairs
    for (int i=0;i<sumOfPairs.size(); i++) {
        std::cout << sumOfPairs.at(i).first  << " ----> " << sumOfPairs.at(i).second << std::endl;
    }
    std::cout << std::endl;
}


int nonDivisibleSubset(int k, std::vector<int> s) 
{
   
  std::set<int> indexes;
  int index = 0;
  std::vector<std::vector<int>> subSets = possibleSubArrays(s,0,0);
  for(auto sArray : subSets)
  {
    for(int j = 0; j < sArray.size() - 1; j++)
    {
      int sum = 0;
      if((sArray.at(j) + sArray.at(j+1)) % k != 0)
        indexes.insert(index);
    }
    index++;
  }

  int i =0;
  for(auto i : indexes)
  {
      subSets.at(i)
  }


  return 0;

}

int main()
{

  std::vector<int> temp = { 19,10,12,10,24,25,22 };
  int k = 4;

  //sumOfPairs(temp);

  std::cout << nonDivisibleSubset(k, temp) << std::endl;
  


  return 0;
}
