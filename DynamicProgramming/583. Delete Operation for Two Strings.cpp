//
// Created by Suhas Reddy on 3/7/25.
//

//O(m*n) time and space complexity
class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int m=word1.size(), n=word2.size();

    vector<vector<int>>dp(m+1, vector<int>(n+1,0));

    for(int i=0;i<=m; i++)
      dp[i][0]=i;

    for(int j=0;j<=n; j++)
      dp[0][j]=j;


    for(int i=1;i<=m; i++)
    {
      for(int j=1;j<=n; j++)
      {
        if(word1[i-1]==word2[j-1])
          dp[i][j]=dp[i-1][j-1];
        else
          dp[i][j]=1+min({dp[i-1][j], dp[i][j-1]});
      }
    }
    return dp[m][n];
  }
};






class Solution
{
public:
  int calculate_LCS(string& s, string& r, int i, int j, vector<vector<int>>&dp)
  {
    //base case
    if(i<=0 ||j<=0)
      return 0;

    if(dp[i][j]!=-1)
      return dp[i][j];

    if(s[i-1]==r[j-1])
    {
      dp[i][j]=1+calculate_LCS(s, r, i-1, j-1, dp);
      return dp[i][j];
    }
    else
    {
      dp[i][j]=max(calculate_LCS(s, r, i, j-1, dp), calculate_LCS(s, r, i-1, j, dp));
      return dp[i][j];
    }
  }

  int minDistance(string word1, string word2)
  {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
    return m+n-2*(calculate_LCS(word1, word2, m, n, dp));

  }
};
