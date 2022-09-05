#include <iostream>
#include <string>
#include <math.h>


// https://leetcode.com/problems/longest-happy-prefix/

class Solution {
  public:
    std::string longestPrefix(std::string s) {
      long prefixHash = 0;
      long suffixHash = 0;

      long i = 0;
      long j = s.size() - 1;
      long maxLength = 0;
      long mul = 1;
      long mod = 1e9 + 7;

      while (i < s.size() - 1) {
        prefixHash = ((prefixHash * 29) + s[i]) % mod;
        suffixHash = (suffixHash + (s[j] * mul)) % mod;

        if (prefixHash == suffixHash) {
          maxLength = i + 1;
        }

        mul = mul * 29 % mod;
        i += 1;
        j -= 1;
      }

      return s.substr(0, maxLength);
    }
};


int main()
{
  Solution SolutionInstance;

  std::string s = "lel";

  std::string result = SolutionInstance.longestPrefix(s);

  std::cout << "result is: " << result << std::endl;
}
