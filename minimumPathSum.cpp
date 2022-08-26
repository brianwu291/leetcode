#include <iostream>
#include <vector>

// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
  int minPathSum(std::vector<std::vector<int>> &grid)
  {
    int m = grid.size();    // how many row
    int n = grid[0].size(); // how many column

    std::vector<std::vector<int>> dp;
    for (int i = 0; i < m; i += 1)
    {
      std::vector<int> empty;
      empty.assign(n, 0);
      dp.push_back(empty);
    }
    dp[0][0] = grid[0][0];

    // go through first row and set val
    for (int i = 1; i < n; i += 1)
    {
      int curVal = grid[0][i];
      dp[0][i] = dp[0][i - 1] + curVal;
    }

    // go through first column and set val
    for (int i = 1; i < m; i += 1)
    {
      int curVal = grid[i][0];
      dp[i][0] = dp[i - 1][0] + curVal;
    }

    // now we have first row and column
    // go through from [1][1]
    for (int i = 1; i < n; i += 1)
    {
      for (int j = 1; j < m; j += 1)
      {
        int curVal = grid[j][i];
        dp[j][i] = std::min(dp[j][i - 1], dp[j - 1][i]) + curVal;
      }
    }

    return dp[m - 1][n - 1];
  }
};
