#include <iostream>
#include <vector>
// #include <algorithm>

// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

/**
 * 1,2,3,4,.....10,5,3
 * 0   i           j n-1
 * [0 ~ i] increase
 * arr[i] <= arr[j] ?
 * [j ~ n - 1] increase
*/

class Solution
{
public:
  int findLengthOfShortestSubarray(std::vector<int> &arr)
  {
    int length = arr.size();

    int result = length - 1;

    int j = length - 1;
    while (j - 1 >= 0 && arr[j] >= arr[j - 1])
    {
      j -= 1;
    }
    result = std::min(result, j);

    if (result == 0)
      return result;

    for (int i = 0; i < length; i += 1)
    {
      if (i - 1 >= 0 && arr[i - 1] > arr[i])
        break;
      while (j < length && arr[i] > arr[j])
      {
        j += 1;
      }
      result = std::min(result, j - i - 1);
    }

    return result;
  }
};
