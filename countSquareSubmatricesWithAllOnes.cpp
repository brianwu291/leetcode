#include <iostream>
#include <vector>

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution
{
public:
  int countSquares(std::vector<std::vector<int>> &matrix)
  {
    int result = 0;
    int rowLength = matrix.size();    // 幾列
    int colLength = matrix[0].size(); // 幾行
    std::vector<std::vector<int>> dp = (std::vector<std::vector<int>>(
        rowLength, std::vector<int>(colLength)));
    // 處理第一列
    for (int j = 0; j < colLength; j += 1)
    {
      if (matrix[0][j] == 1)
      {
        dp[0][j] = 1;
        result += 1;
      }
    }
    // 處理第一行
    for (int i = 1; i < rowLength; i += 1)
    {
      if (matrix[i][0] == 1)
      {
        dp[i][0] = 1;
        result += 1;
      }
    }
    for (int i = 1; i < rowLength; i += 1)
    {
      for (int j = 1; j < colLength; j += 1)
      {
        if (matrix[i][j] == 1)
        {
          int minSide = std::min(
              dp[i - 1][j - 1],
              std::min(dp[i - 1][j], dp[i][j - 1]));

          dp[i][j] = minSide + 1; // 記得加自己
          result += dp[i][j];
        }
      }
    }
    return result;
  }
};
