#include <iostream>
#include <vector>

// https://leetcode.com/problems/house-robber-ii/
class Solution
{
public:
  int solve(std::vector<int> &nums)
  {
    int length = nums.size();
    if (length == 1)
      return nums[0];

    std::vector<int> dp(length);
    dp[0] = std::max(0, nums[0]);
    dp[1] = std::max(dp[0], nums[1]);

    for (int i = 2; i < length; i += 1)
    {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    int lastIndexOfDp = dp.size() - 1;

    return dp[lastIndexOfDp];
  }

  int rob(std::vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    // val1 = 0,1,2... n - 2;
    // val2 = 1,2,3,...n - 1;
    // max(val1, val2);
    std::vector<int> numsWithFirstOne;
    std::vector<int> numsWithLastOne;

    for (int i = 0; i < n; i += 1)
    {
      if (i >= 0 && i < n - 1)
      {
        numsWithFirstOne.push_back(nums[i]);
      }
      if (i >= 1 && i < n)
      {
        numsWithLastOne.push_back(nums[i]);
      }
    }

    int resWithfirst = solve(numsWithFirstOne);
    int resWithLast = solve(numsWithLastOne);

    int finalRes = std::max(resWithfirst, resWithLast);

    return finalRes;
  }
};

int main()
{
  Solution SolutionInstance;

  std::vector<int> nums = {1, 1, 2, 1};

  int result = SolutionInstance.rob(nums);

  std::cout << "result is: " << result << std::endl;

  return 0;
}
