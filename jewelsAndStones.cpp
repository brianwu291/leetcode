#include <iostream>
#include <unordered_map>
#include <string>

// https://leetcode.com/problems/jewels-and-stones/

class Solution
{
public:
  int numJewelsInStones(std::string jewels, std::string stones)
  {

    std::unordered_map<std::string, int> tempMap;

    for (int i = 0; i < jewels.size(); i += 1)
    {
      char curJewelChar = jewels[i];
      std::string curJewel;
      curJewel.push_back(curJewelChar);
      if (tempMap.count(curJewel) == 0)
      {
        tempMap[curJewel] = 1;
      }
    }

    int result = 0;

    for (int i = 0; i < stones.size(); i += 1)
    {
      char curStoneChar = stones[i];
      std::string curStone;
      curStone.push_back(curStoneChar);
      if (tempMap.count(curStone) > 0)
      {
        result += 1;
      }
    }

    return result;
  }
};