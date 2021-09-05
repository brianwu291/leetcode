#include <iostream>
#include <vector>

// https://leetcode.com/problems/house-robber/

// 2, 7, 9, 3, 1,

class Solution
{
public:
  int rob(std::vector<int> &nums)
  {
    int length = nums.size();

    int goRob = nums[0], noRob = 0;

    for (int i = 1; i < length; i += 1)
    {
      int tempGoRob = goRob, tempNoRob = noRob;

      noRob = std::max(tempGoRob, tempNoRob);

      goRob = tempNoRob + nums[i];
    }

    return std::max(goRob, noRob);
  }
};
