#include<iostream>
#include <vector>

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
  public:
    int findMin(std::vector<int>& nums) {
      int length = nums.size();
      if (length == 1 || nums[0] < nums[length - 1]) {
        return nums[0];
      }
      if (length == 2) {
        return nums[0] < nums[1] ? nums[0] : nums[1];
      }
      int result;
      bool isFound = false;
      int i = 0, j = length - 1;
      while (i < j && !isFound) {
        if (nums[i] > nums[i + 1]) {
          result = nums[i + 1];
          isFound = true;
        }
        if (nums[j - 1] > nums[j]) {
          result = nums[j];
          isFound = true;
        }
        i += 1;
        j -= 1;
      }
      return result;
    }
};
