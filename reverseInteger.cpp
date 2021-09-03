#include<iostream>

// https://leetcode.com/problems/reverse-integer/

class Solution {
  public:
    int reverse(int x) {
      int result = 0, rest;

      while (x != 0) {
        if (result >= 214748365 || result <= -214748365) {
          return 0;
        }

        rest = x % 10;

        result = result * 10 + rest;

        x /= 10;
      }

      return result;
    }
};
