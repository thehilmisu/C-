#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> magic_squares_3x3 = {
    {8, 1, 6, 3, 5, 7, 4, 9, 2},
    {4, 3, 8, 9, 5, 1, 2, 7, 6},
    {2, 9, 4, 7, 5, 3, 6, 1, 8},
    {6, 7, 2, 1, 5, 9, 8, 3, 4},
    {6, 1, 8, 7, 5, 3, 2, 9, 4},
    {8, 3, 4, 1, 5, 9, 6, 7, 2},
    {4, 9, 2, 3, 5, 7, 8, 1, 6},
    {2, 7, 6, 9, 5, 1, 4, 3, 8}
};

int formingMagicSquare(vector<vector<int>> matrix) {
  
  vector<int> whole;
  for(int i=0;i<matrix.size();i++)
    for(int j=0;j<matrix.at(i).size();j++)
      whole.push_back(matrix.at(i).at(j));

  int min_cost = 100;
  for (int i = 0; i < 8; i++) {
      int cost = 0;
      for (int j = 0; j < 9; j++) cost += abs(whole.at(j) - magic_squares_3x3.at(i).at(j));
      if (cost < min_cost) min_cost = cost;
    }

  return min_cost;

}
int main() {
    
  
  vector<vector<int>> matrix = {{5,3,4},{1,5,8},{6, 4, 2}}; 

  cout << formingMagicSquare(matrix) << endl;

  return 0;
}
