#include <iostream>
#include <vector>

// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution
{
public:
  int minSubArrayLen(int target, std::vector<int> &nums)
  {
    int length = nums.size();
    if (length == 1)
      return nums[0] == target ? 1 : 0;

    int i = 0, j = 1, result = INT32_MAX, tempTotal = nums[i] + nums[j];

    while (j < length && i < length - 1)
    {
      if (nums[i] >= target || nums[j] >= target)
        return 1;
      if (tempTotal >= target)
      {
        int tempResult = j - i + 1;
        result = tempResult > result ? result : tempResult;
        tempTotal -= nums[i];
        i += 1;
      }
      else
      {
        j += 1;
        if (j < length)
        {
          tempTotal += nums[j];
        }
      }
    }

    return result == INT32_MAX ? 0 : result;
  }
};
