function coinChange(coins: number[], amount: number): number {
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// dp[0] = 0
// dp[1] = 1 
// dp[2] = 1
// dp[3] = dp[2] + dp[1] || dp[1] + dp[1] + dp[1]
// dp[4] = dp[3] + dp[1] || dp[2] + dp[2]
  if (amount === 0) {
    return 0;
  }
  const dp = new Map<number, number>();
  dp.set(0, 0);
  for (let am = 1; am <= amount; am += 1) {
    for (let i = 0; i < coins.length; i += 1) {
      const coin = coins[i];
      dp.set(coin, 1)
      const rest = am - coin;
      // rest zero or bigger, means this coin potentially can be
      const potentialValid = rest >= 0 && dp.has(rest);
      if (potentialValid) {
        if (dp.has(am)) {
          const newVal = Math.min(dp.get(am) as number, dp.get(rest) as number + 1);
          dp.set(am, newVal);
        } else {
          dp.set(am, dp.get(rest) as number + 1);
        }
      }
    }
  }

  return dp.has(amount) ? dp.get(amount) as number : -1;
}