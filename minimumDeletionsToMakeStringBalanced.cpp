#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

//       a a b a   // 1
// pre  [0,0,1,1]
// suf  [4,3,3,2]

// b b a a a a a b b
// 2

class Solution
{
public:
  std::string A = "a";
  std::string B = "b";

  int minimumDeletions(std::string s)
  {
    int length = s.size();
    // count "b"
    std::vector<int> pre(length);
    std::string firstStr;
    firstStr.push_back(s[0]);
    pre[0] = firstStr == B ? 1 : 0;
    for (int i = 1; i < length; i += 1)
    {
      std::string curStr;
      curStr.push_back(s[i]);
      int count = curStr == B ? 1 : 0;
      pre[i] = pre[i - 1] + count;
    }
    // count "a"
    std::vector<int> suf(length);
    std::string lastStr;
    lastStr.push_back(s[length - 1]);
    suf[length - 1] = lastStr == A ? 1 : 0;
    for (int i = length - 2; i >= 0; i -= 1)
    {
      std::string curStr;
      curStr.push_back(s[i]);
      int count = curStr == A ? 1 : 0;
      suf[i] = suf[i + 1] + count;
    }

    int result = std::min(pre[length - 1], suf[0]);
    for (int i = 0; i < length - 1; i += 1)
    {
      result = std::min(result, pre[i] + suf[i + 1]);
    }
    return result;
  }
};
