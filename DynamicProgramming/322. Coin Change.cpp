class Solution {
public:
  int helper(vector<int>& coins, int amount, int index, vector<vector<int>>& dp)
  {
    if (amount == 0)
      return 0;

    if (amount < 0 || index >= coins.size())
      return INT_MAX - 1;

    if (dp[index][amount] != -1)
      return dp[index][amount];

    // Take the coin
    int take = 1 + helper(coins, amount - coins[index], index, dp);

    // Skip the coin
    int skip = helper(coins, amount, index + 1, dp);

    // Store the minimum result in dp
    return dp[index][amount] = min(take, skip);
  }

  int coinChange(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int result = helper(coins, amount, 0, dp);
    return (result == INT_MAX - 1) ? -1 : result;
  }
};

class Solution2 {
public:

  int coinChange(vector<int>& coins, int amount)
  {

    if(coins.size()==0)
      return 0;

    /*
              amount -->
         coins
         |
         |

    */

    vector<vector<int>> dp(coins.size()+1, vector<int>(amount + 1,0));

    for(int j=0;j<amount+1; j++)
    {
      dp[0][j]=amount+1;
    }

    for(int i=1;i<coins.size()+1; i++)
    {
      for(int j=1; j<amount+1; j++)
      {
        if(j<coins[i-1]) //when amount is lesser than value of coin
          dp[i][j]= dp[i-1][j];
        else
          dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
      }
    }

    return (dp[coins.size()][amount]>amount)?-1:dp[coins.size()][amount];
  }
};



//more optimal, took from discussion
class Solution3
{
public:
    int coinChange(vector<int>& coins, int n)
  {
        int dp[++n];
        dp[0] = 0;
        // more convenient to have the coins sorted
        sort(begin(coins), end(coins));
        // populating our dp array
        for (int i = 1; i < n; i++)
        {
            // setting dp[0] base value to 1, 0 for all the rest
            dp[i] = INT_MAX;
            for (int c: coins)
            {
                if (i - c < 0) break;
                // if it was a previously not reached cell, we do not add use it
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};