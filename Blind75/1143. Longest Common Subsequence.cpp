//
// Created by Suhas Reddy on 2/16/25.
//

//O(m*n) time and space complexity.

class Solution {
public:

  int helper(const string& text1, const string& text2, int i, int j, vector<vector<int>>& dp)
  {
    //base case
    if(i>=text1.size() || j>=text2.size())
      return 0;

    //memoization case
    if(dp[i][j]!=-1)
      return dp[i][j];

    //when characters match add one to length.
    if(text1[i]==text2[j])
      return dp[i][j]=1+helper(text1, text2, i+1, j+1, dp);
    else
      return dp[i][j]=max(helper(text1, text2, i+1, j, dp), helper(text1, text2, i, j+1, dp));

    return dp[i][j];
  }

  int longestCommonSubsequence(string text1, string text2)
  {
    int m= text1.size();
    int n =text2.size();

    vector<vector<int>>dp(m, vector<int>(n,-1));

    helper(text1, text2, 0, 0, dp);

    return dp[0][0];
  }
};