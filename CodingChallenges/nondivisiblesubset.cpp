
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

void sumOfPairs(std::vector<int> arr, int b)
{

    std::vector<std::pair<int, std::vector<int>>> sumOfPairs; // Vector to store the sums of pairs

    std::vector<std::vector<int>> subArrays = possibleSubArrays(arr, 0, 0);
    int n = subArrays.size(); 
    //std::cout << n << std::endl;
    for (int i = 0; i < n; i++) 
    {
       int size = subArrays.at(i).size();
       for(int j=0;j<subArrays.at(i).size();j++)
          for(int k=1;k<subArrays.at(i).size();k++)
            if((subArrays.at(i).at(k-1) + subArrays.at(i).at(k)) %  b != 0)
              sumOfPairs.push_back(std::make_pair(i, subArrays.at(i)));
    }

    int max_index = 0;
    
    for(int i =0; i< sumOfPairs.size(); i++)
    {   
        int s = sumOfPairs.at(i).second.size();
        max_index = std::max(s, max_index);
    }

    std::cout << max_index << std::endl;

    std::cout << sumOfPairs.at(max_index).first << " .... "  << std::endl;

    for(auto i : sumOfPairs.at(7).second)
      std::cout << i << std::endl;

  
}

int nonDivisibleSubset(int k, std::vector<int> s, int a)
{
    //std::vector<std::vector<int>> subArrays = possibleSubArrays(arr, 0, 0);

    sumOfPairs(s, k);

    return 0;

}
int nonDivisibleSubset(int k, std::vector<int> s) 
{
   
  std::set<int> indexes;
  int index = 0;
  for(auto sArray : possibleSubArrays(s,0,0))
  {
    for(int j = 0; j < sArray.size() - 1; j++)
    {
      int sum = 0;
      if((sArray.at(j) + sArray.at(j+1)) % k != 0)
        indexes.insert(index);
    }
    index++;
  }

  for(auto i : indexes)
    std::cout << i << std::endl;


  return 0;

}

int main()
{

  std::vector<int> temp = { 19,10,12,10,24,25,22 };
  int k = 4;

  //sumOfPairs(temp);

  std::cout << nonDivisibleSubset(k, temp, 1) << std::endl;
  


  return 0;
}
