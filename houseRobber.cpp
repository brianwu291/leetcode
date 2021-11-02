#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/house-robber/

// 2, 7, 9, 3, 1,

class Solution
{
public:
  int rob(std::vector<int> &nums)
  {
    int length = nums.size();
    if (length == 1) return nums[0];

    std::vector<int> dp(length);
    dp[0] = std::max(0, nums[0]);
    dp[1] = std::max(dp[0], nums[1]);

    for (int i = 2; i < length; i += 1) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    int lastIndexOfDp = dp.size() - 1;

    return dp[lastIndexOfDp];
  }
};

int main()
{
  Solution SolutionInstance;

  std::vector<int> nums = {1, 2, 5};

  int amount = 50;

  int result = SolutionInstance.rob(nums);

  std::cout << "result is: " << result << std::endl;

  return 0;
}

