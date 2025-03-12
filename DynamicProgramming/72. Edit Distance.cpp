//
// Created by Suhas Reddy on 3/7/25.
//


/*
 * dp[i][j] represents no of changes need to be done for
 * word1 and word2 to match upto index i-1 and j-1.
 *
 */

//O(m*n) time and space complexity
//Bottom up DP
class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size(), n = word2.size();

    if(m==0)
      return n;

    if(n==0)
      return m;

    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    for(int i=0;i<=m;i++)
      dp[i][0]=i;

    for(int j=0;j<=n;j++)
      dp[0][j]=j;

    for(int i=1;i<=m; i++)
    {
      for(int j=1;j<=n; j++)
      {
        if(word1[i-1]==word2[j-1]) //if char matches, no need to do a change
          dp[i][j]=dp[i-1][j-1];

        else //pick the least of {replace_char, remove_char, add_char}
          dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j], dp[i][j-1]});
      }
    }
    return dp[m][n];
  }
};


//Top-Down DP
class Solution2
{
  public:
  vector<vector<int>> dp;
  int minDistance(string word1, string word2)
  {
    dp.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));

    return helper(word1, word2, word1.size(), word2.size());
  }

  int helper(string &word1, string &word2, int index1,
                       int index2)
  {
    //base cases
    if (index1 == 0)
      return index2;

    if (index2 == 0)
      return index1;

    if (dp[index1][index2] != -1)
      return dp[index1][index2];

    int distance = 0;

    if (word1[index1-1] == word2[index2-1])
      distance= helper(word1, word2, index1-1, index2-1);

    else
    {
      int insertOperation = helper(word1, word2, index1, index2-1);
      int deleteOperation = helper(word1, word2, index1-1, index2);
      int replaceOperation = helper(word1, word2, index1-1, index2-1);
      distance = 1+ min({insertOperation, deleteOperation, replaceOperation});
    }

    dp[index1][index2] = distance;
    return distance;
  }
};