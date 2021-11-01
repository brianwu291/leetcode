#include <iostream>
#include <vector>

// coins = [4, 5, 6], amount = 9
// https://leetcode.com/problems/coin-change/
class Solution
{
public:
  int coinChange(std::vector<int> &coins, int amount)
  {
    std::vector<int> dp(amount + 1);
    dp[0] = 0;

    int coinsLength = coins.size();
    int i, j;

    // dp[1], dp[2].... dp(amount)
    for (i = 1; i <= amount; i += 1)
    {
      dp[i] = INT32_MAX;

      for (j = 0; j < coinsLength; j += 1)
      {
        /* dp(sum) = (
          min(dp(sum - coins[j]) + 1, ..., dp(sum - coins[coinsLength - 1]) + 1)
        )
        */
        // edge case:
        // i - coins[j] < 0 ->  vector cannot have negative int key
        // dp[i - coins[j]] == INT32_MAX -> will overflow
        if (i >= coins[j] && dp[i - coins[j]] != INT32_MAX)
        {
          dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
        }
      }
    }

    return dp[amount] == INT32_MAX ? -1 : dp[amount];
  }
};

int main()
{
  Solution SolutionInstance;

  std::vector<int> coins = {1, 2, 5};

  int amount = 50;

  int result = SolutionInstance.coinChange(coins, amount);

  std::cout << "result is: " << result << std::endl;

  return 0;
}
