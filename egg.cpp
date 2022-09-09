
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int superEggDrop(int K, int N)
  {
    // dp initialized to only 1 egg, n floors need test n times.
    vector<int> dp(N + 1);
    for (int n = 0; n <= N; n++)
      dp[n] = n;

    for (int k = 2; k <= K; k++)
    {
      vector<int> new_dp(N + 1);
      new_dp[0] = 0;
      int i = 1;
      for (int n = 1; n <= N; n++)
      {
        // opt for the for loop to avoid TLE.
        // int steps = INT_MAX;
        // for (int i = 1; i <= n; i++)
        //  steps = min(steps, max(dp[i - 1], new_dp[n - i]));
        while (i < n && dp[i - 1] < new_dp[n - i])
          ++i;
        new_dp[n] = 1 + max(dp[i - 1], new_dp[n - i]);
      }
      dp.swap(new_dp);
    }
    return dp[N];
  }
};

int main()
{

  Solution s;

  cout << s.superEggDrop(250, 7) << endl;


  return 0;
}
