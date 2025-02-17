//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int climbStairs(int n)
  {
    if (n == 1 ||n==2)
    {
      return n;
    }

    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

class Solution2 {
public:
  int climbStairs(int n)
  {
    if (n == 1 ||n==2)
    {
      return n;
    }

    int prev2=1, prev1=2;
    int result=0;
    for (int i = 3; i <= n; i++)
    {
      result = prev1+prev2;
      prev2=prev1;
      prev1=result;
    }
    return result;
  }
};
