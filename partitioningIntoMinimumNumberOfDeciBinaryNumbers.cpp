#include <iostream>
#include <string>

// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution
{
public:
  int minPartitions(std::string n)
  {
    int length = n.length();
    int res = 0;
    for (int i = 0; i < length; i += 1)
    {
      char curNumChar = n[i];
      int temp = curNumChar - '0';
      if (temp == 9)
        return temp;
      res = std::max(temp, res);
    }
    return res;
  }
};
