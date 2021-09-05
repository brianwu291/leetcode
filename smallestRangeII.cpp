#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/smallest-range-ii/

class Solution
{
public:
  int smallestRangeII(std::vector<int> &nums, int k)
  {
    std::sort(nums.begin(), nums.end());

    int length = nums.size();

    int result = nums[length - 1] - nums[0];

    for (int i = 0; i < length - 1; i += 1)
    {
      int max = std::max(nums[i] + k, nums[length - 1] - k);
      int min = std::min(nums[0] + k, nums[i + 1] - k);

      result = std::min(result, max - min);
    }

    return result;
  }
};
