#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// 1, 4, 5, 13
// k = 8
// i
//       j

class Solution
{
public:
  int maxFrequency(std::vector<int> &nums, int k)
  {
    int length = nums.size();
    if (length == 1)
      return 1;

    std::sort(nums.begin(), nums.end());

    long count = 0;
    long i = 0;
    long result = 1;
    for (int j = 1; j < length; j += 1)
    {
      long nextGap = nums[j] - nums[j - 1];
      count += (j - i) * nextGap;
      while (count > k)
      {
        count -= nums[j] - nums[i];
        i += 1;
      }
      result = std::max(result, j - i + 1);
    }
    return result;
  }
};
