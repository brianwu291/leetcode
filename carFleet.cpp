#include <vector>
#include <unordered_map>
#include <algorithm>

// https://leetcode.com/problems/car-fleet/

class Solution
{
public:
  int carFleet(int target, std::vector<int> &position, std::vector<int> &speed)
  {
    int totalLength = position.size();
    if (totalLength == 1)
      return 1;

    std::unordered_map<int, double> arrivedTimePosMap;
    for (int i = 0; i < totalLength; i += 1)
    {
      double gap = target - position[i];
      double time = gap / speed[i];
      arrivedTimePosMap[position[i]] = gap / speed[i];
    }

    std::sort(position.begin(), position.begin() + totalLength);

    int result = 0;
    for (int j = totalLength - 1; j > 0; j -= 1)
    {
      int curCarPos = position[j];
      int preCarPos = position[j - 1];
      double curCarArrivedTime = arrivedTimePosMap[curCarPos];
      double preCarArrivedTime = arrivedTimePosMap[preCarPos];
      if (curCarArrivedTime < preCarArrivedTime)
      {
        result += 1;
      }
      else
      {
        arrivedTimePosMap[preCarPos] = arrivedTimePosMap[curCarPos];
      }
    }

    result += 1;
    return result;
  }
};
