#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int pickingNumbers(vector<int> array) {

  std::sort(array.begin(), array.end());

	int result = 0;
	int count = 1;
	int subarray_first_element = array[0];

	for (int i = 1; i < array.size(); ++i)
	{
		if (subarray_first_element == array[i] || subarray_first_element + 1 == array[i])
		{
			count++;
		}
		else
		{
			if (count > result)
			{
				result = count;
			}
			count = 1;
			subarray_first_element = array[i];
		}
	}

	if (count > result)
	{
		result = count;
	}
	
  return result;
}

int main() {
    
 

  
  vector<int> input = {1,1,2,2,4,4,5,5,5}; 

  cout << pickingNumbers(input) << endl;

  return 0;
}
