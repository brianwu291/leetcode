#include <iostream>
#include <vector>

// https://leetcode.com/problems/triangle/

class Solution {
  public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
      int length = triangle.size();
      int topNum = triangle[0][0];
      if (length == 1) return topNum;
      
      std::vector<std::vector<int>> dp(length, std::vector<int>(0));
      dp[0].push_back(topNum);
      
      int result = INT32_MAX;
      
      for (int i = 1; i < length; i += 1) {
        for (int j = 0; j < triangle[i].size(); j += 1) {
          if (j == 0) {
            dp[i].push_back(dp[i - 1][j] + triangle[i][j]);
            if (i == length - 1) {
              result = std::min(result, dp[i][j]);
            }
          } else if (j == triangle[i].size() - 1) {
            dp[i].push_back(dp[i - 1][j - 1] + triangle[i][j]);
            if (i == length - 1) {
              result = std::min(result, dp[i][j]);
            }
          } else {
            dp[i].push_back(std::min(dp[i - 1][j] + triangle[i][j] , dp[i - 1][j - 1] + triangle[i][j]));
            if (i == length - 1) {
              result = std::min(result, dp[i][j]);
            }
          }
        }
      }
      
      return result;
    }
};

int main()
{
  Solution SolutionInstance;

  std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};

  int result = SolutionInstance.minimumTotal(triangle);

  std::cout << "result is: " << result << std::endl;

  return 0;
}
