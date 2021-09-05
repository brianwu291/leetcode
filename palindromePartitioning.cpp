#include <iostream>
#include <vector>
#include <string>

// https://leetcode.com/problems/palindrome-partitioning/

class Solution
{
public:
  bool isPalindrome(std::string &str)
  {
    bool result = true;
    int stringLength = str.length();
    int start = 0, end = stringLength - 1;
    while (result && start < end)
    {
      if (str[start] != str[end])
      {
        result = false;
      }
      start += 1;
      end -= 1;
    }
    return result;
  }

  void getResult(std::string str, std::vector<std::vector<std::string>> &res, std::vector<std::string> &tempRes)
  {
    if (str.empty())
    {
      res.push_back(tempRes);
    }

    int strLength = str.size();
    for (int i = 0; i < strLength; i += 1)
    {
      std::string leftStr = str.substr(0, i + 1);

      if (isPalindrome(leftStr))
      {
        tempRes.push_back(leftStr);
        std::string restStr = str.substr(i + 1);
        getResult(restStr, res, tempRes);
        tempRes.pop_back();
      }
    }
  }

  std::vector<std::vector<std::string>> partition(std::string s)
  {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> tempResultVector;
    getResult(s, result, tempResultVector);
    return result;
  }
};
