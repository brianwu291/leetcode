#include <iostream>
#include <vector>
#include <cmath>

// coins = [[-1,0,3,5,9,12], target = 9
// https://leetcode.com/problems/binary-search
class Solution
{
public:
  int search(std::vector<int>& nums, int target)
  {
  return _innerSearch(nums, target, 0, nums.size() - 1);
  }

  int _innerSearch(std::vector<int>& nums, int target, int startIndex, int endIndex) {
    int range = endIndex - startIndex + 1;
    if (range <= 2) {
      if (nums[startIndex] == target) return startIndex;
      if (nums[endIndex] == target) return endIndex;
      return -1;
    }
    int middleIndex = std::floor((endIndex + startIndex) / 2);
    int nextStartIndex = startIndex;
    int nextEndIndex = endIndex;
    if (nums[middleIndex] < target) {
      nextStartIndex = middleIndex + 1;
    } else {
      nextEndIndex = middleIndex;
    }
    return _innerSearch(nums, target, nextStartIndex, nextEndIndex);
  }
};

int main()
{
  Solution SolutionInstance;

  std::vector<int> nums = {-1, 0,3,5,9,12};

  int target = 9;

  int result = SolutionInstance.search(nums, target);

  std::cout << "result is: " << result << std::endl;

  return 0;
}
