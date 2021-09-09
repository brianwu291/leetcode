#include <iostream>
#include <vector>

// 3, 2, 2, 4, 1, 4
// 3  5  7  11 12 16
// 5
// 16

class Solution
{
  public:
    bool check(std::vector<int>& weights, int capicity ,int days) {
      int weightLength = weights.size();

      int deleverDays = 0;
      int i = 0;
      while (i < weightLength)
      {
        int j = i;
        int tempSum = 0;
        while (j < weightLength && (tempSum + weights[j]) <= capicity)
        {
          tempSum += weights[j];
          j += 1;
        }
        deleverDays += 1;
        if (deleverDays > days) return false;
        i = j;
      }

      return true;
    }

    int shipWithinDays(std::vector<int>& weights, int days)
    {
      int weightLength = weights.size();

      if (weightLength == 1) return 1;
      
      int left = 0, right = 0; 
      /** 
       * 找出總和的 weight &
       * 總和除以 days;
       * left -------- right
       * */
      for (int i = 0; i < weightLength; i++)
      {
        right += weights[i];
      }
      left = right / days;
      // 答案一定是在這兩者之間

      while (left < right)
      {
        int capacity = left + (right - left) / 2;

        if (check(weights, capacity, days))
        { // 可以裝完
          right = capacity;
        } else
        { // 不夠裝
          left = capacity + 1;
        } 
      }

      return left;
    }
};

int main() {
  Solution SolutionInstance;

  std::vector<int> weights = { 3, 2, 2, 4, 1, 4 };

  int days = 3;

  int result = SolutionInstance.shipWithinDays(weights, days);

  std::cout << "result is: " << result << std::endl;

  return 0;
}
