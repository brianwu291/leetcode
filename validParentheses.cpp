#include <iostream>
#include <string>
#include <vector>

// https://leetcode.com/problems/valid-parentheses/

class Solution {
  public:
    bool isValid(std::string s) {
      int length = s.size();
      if (length == 1) return false;
      
      std::vector<std::string> openedStack;
      bool result = true;
      for (int i = 0; i < length && result; i += 1)
      {
        char curChar = s[i];
        std::string curStr;
        curStr.push_back(curChar);
        if (
          curStr == "{"
          || curStr == "["
          || curStr == "("
        )
        {
          openedStack.push_back(curStr);
        } else if (openedStack.size() > 0)
        {
          std::string curOpenedStr = openedStack.back();
          openedStack.pop_back();
          if (curStr == "}" && curOpenedStr != "{")
            result = false;
          if (curStr == "]" && curOpenedStr != "[")
            result = false;
          if (curStr == ")" && curOpenedStr != "(")
            result = false;
        } else {
          return false;
        }
      }
      if (result == false) return false;
      return openedStack.empty();
    }
};
