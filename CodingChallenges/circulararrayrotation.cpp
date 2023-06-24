#include <algorithm>
#include <iostream>
#include <vector>


//solution is correct but failed in 6 test cases out of 15 due to time limit
std::vector<int> circularArrayRotation(std::vector<int> a, int k, std::vector<int> queries) {

  std::vector<int> result;  

  for(int i=0;i<k;i++)
  {
    std::rotate(a.rbegin(), a.rbegin() + 1, a.rend()); 
  }

  for(int j=0;j<queries.size();j++)
    result.push_back(a.at(queries.at(j)));

 
  return result;
}

//solution with passes all test cases
std::vector<int> circularArrayRotation2(std::vector<int> a, int k, std::vector<int> queries)
{

    int arr_size = a.size();
    while (k > arr_size)
    {
        k = k - arr_size;
    }

    std::vector<int> new_array;
    for (int i = arr_size - k; i < arr_size; ++i)
    {
        new_array.push_back(a[i]);
    }
    for (int i = 0; i < arr_size - k; ++i)
    {
        new_array.push_back(a[i]);
    }

    std::vector<int> res;
    for(int i = 0; i < queries.size(); ++i)
    {
        int val = new_array[queries[i]];
        res.push_back(val);
    }
 
  return res;
}

int main()
{

  std::vector<int> a  = { 3, 4, 5 };
  int k = 2; //number of times that operation take place
  std::vector<int> queries = {1 , 2}; //indexes to query

  for(auto i : circularArrayRotation(a, k, queries))
    std::cout << i << std::endl;
  


  return 0;
}
