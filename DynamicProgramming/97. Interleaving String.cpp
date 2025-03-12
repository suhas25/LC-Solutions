//
// Created by Suhas Reddy on 3/8/25.
//

/*
 * dp[i][j] indicates if its possibe to construct s3 upto index
 * i+j-1 using s1[0...i-1] abd s2[0...j-1]
 * At every instance,we check if we were able to form s3 upto last index and
 * check the current index val with s1 or s2 curr_index val
 */

//O(m*n) time and space complexity. Can optimise space complexity to O(n)
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    if (s3.size() != s1.size()+s2.size())
      return false;

    vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, 0));

    for(int i=0;i<=s1.size(); i++)
    {
      for(int j=0;j<=s2.size(); j++)
      {
        if(i==0 && j==0)
          dp[i][j]=true; //its possible to form s3[-1] .ie empty string s3.
        else if(i==0)
          dp[i][j]= dp[i][j-1] && s2[j-1] == s3[j-1];
        else if (j==0)
          dp[i][j]= dp[i-1][j] && s1[i-1] == s3[i-1];
        else
          dp[i][j]= (dp[i-1][j] && s1[i-1]==s3[i+j-1]) ||
                     (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
      }
    }
    return dp[s1.size()][s2.size()];
  }
};


//Top down dpization
class Solution2
{
  public:
  bool helper(string s1, int i, string s2, int j, string s3, int k,
                     vector<vector<int>>& dp)
    {
    if (i == s1.length())
      return s2.substr(j) == s3.substr(k);

    if (j == s2.length())
      return s1.substr(i) == s3.substr(k);

    if (dp[i][j]!=-1)
      return dp[i][j] == 1 ? true : false;

    bool possible = false;
    if ((s3[k] == s1[i] &&
         helper(s1, i + 1, s2, j, s3, k + 1, dp)) ||
        (s3[k] == s2[j] &&
         helper(s1, i, s2, j + 1, s3, k + 1, dp))) {
      possible = true;
    }
    dp[i][j] = possible ? 1 : 0;
    return possible;
  }
  
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    return helper(s1, 0, s2, 0, s3, 0, dp);
  }
};
