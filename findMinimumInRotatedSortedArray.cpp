#include<iostream>
#include <vector>

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// 4,5,6,7,0,1,2
// 6,7,0,1,2,4,5
// 3,4,5,1,2
// 0       4   6
//       i j
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
      int i = 0, j = length - 1;
      while (i < j) {
        int midIndex = (j + i) / 2;
        int midNum = nums[midIndex];
        if (midNum > nums[j]) {
          i = midIndex + 1;
        } else {
          j = midIndex;
        }
      }
      return nums[i];
    }
};
