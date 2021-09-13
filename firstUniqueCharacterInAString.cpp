#include <iostream>
#include <unordered_map>
#include <string>

// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution
{
public:
  int firstUniqChar(std::string s)
  {
    int length = s.length();
    int resIndex = -1;
    std::unordered_map<std::string, int> tempMap;

    for (int i = 0; i < length; i += 1)
    {
      char curChar = s[i];
      std::string curStr;
      curStr.push_back(curChar);

      if (tempMap.count(curStr) == 0)
      {
        tempMap[curStr] = 1;
      }
      else
      {
        tempMap[curStr] += 1;
      }
    }

    bool isFound = false;
    int j = 0;
    while (!isFound && j < length)
    {
      char curChar = s[j];
      std::string curStr;
      curStr.push_back(curChar);
      if (tempMap[curStr] == 1)
      {
        isFound = true;
        resIndex = j;
      }
      j += 1;
    }

    return resIndex;
  }
};

int main()
{
  Solution SolutionInstance;

  std::string s = "leetcode";

  int result = SolutionInstance.firstUniqChar(s);

  std::cout << "result is " << result << std::endl;
  return 0;
}
