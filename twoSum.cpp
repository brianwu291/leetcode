#include <iostream>
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/two-sum/

class Solution {

  public:

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int> numberIndexMap;

      int numsSize = nums.size();

      for (int i = 0; i < numsSize; i += 1) {
        int num = nums[i];

        int rest = target - num;

        int numberNotExist = numberIndexMap.count(num) == 0;

        if (numberNotExist) {
          numberIndexMap[rest] = i;
        } else {
          std::vector<int> result { i, numberIndexMap[num] };
          return result;
        };
      }

      std::vector<int> result;

      return result;
    }
};
