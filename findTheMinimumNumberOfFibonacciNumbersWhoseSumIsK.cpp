#include <bits/stdc++.h>

// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution {
  public:
    int findMinFibonacciNumbers(int k) {
        if (k <= 0) return 0;
        if (k < 2) return 1;
      
        int secondToLast = 1, lastOne = 1;

        while(lastOne <= k) {
            std::swap(secondToLast, lastOne);
            lastOne += secondToLast;
        }
      
        return 1 + findMinFibonacciNumbers(k - secondToLast);
    }
};
