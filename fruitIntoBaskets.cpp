#include <iostream>
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
  public:
    int totalFruit(std::vector<int>& fruits) {
      int length = fruits.size();
      int result = 0, tempRes = 0;
      int i = 0;
      std::unordered_map <int, int> tempMap;
      while (i < length) {
        int curFruit = fruits[i];
        if (tempMap.count(curFruit) == 0) {
          if (tempMap.size() < 2) {
            tempMap[curFruit] = 1;
            tempRes += 1;
          } else {
            result = tempRes > result ? tempRes : result;
            tempRes = 0;
            int preFruit = fruits[i - 1];
            i -= (tempMap[preFruit] + 1); 
            tempMap.clear();
          }
        } else {
          tempMap[curFruit] += 1;
          tempRes += 1;
        }
        i += 1;
      }
      result = tempRes > result ? tempRes : result;
      return result;
    }
};
