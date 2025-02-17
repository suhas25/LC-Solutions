//
// Created by Suhas Reddy on 2/16/25.
//

//O(n) space complexity with bottom up DP
class Solution
{
public:

  bool wordBreak(string s, vector<string>& wordDict)
  {
    //DP[index] denotes if we have a valid composition to build string starting from index i.
    vector<int>dp(s.size()+1,0);

    dp[s.size()]=1;

    for(int index = s.size()-1; index>=0; index--)
    {
      for(const auto&word:wordDict)
      {
        if(index+word.size()<=s.size() && s.substr(index, word.size())==word)
          dp[index]= dp[index+word.size()];

        if(dp[index]) // if reachable from any word then its valid.
          break;
      }
    }

    return dp[0];
  }
};

//Memoization with O(n) space complexity and O(m*n*t) time complexity
class Solution2
{
public:

  bool helper(string s, vector<string>&wordDict, int index, vector<int>&dp)
  {
    //base case
    if(index==s.size())
      return 1;

    //memoization
    if(dp[index]!=-1)
      return dp[index];

    for(const auto&word:wordDict)
    {
      //controlled recursion
      if(index+word.size()<=s.size() && s.substr(index, word.size())==word)
      {
        auto res= helper(s, wordDict, index+word.size(), dp);

        if(res)
          dp[index]=1;
      }
    }

    if(dp[index]==-1)
      dp[index]=0;

    return dp[index];
  }

  bool wordBreak(string s, vector<string>& wordDict)
  {
    vector<int>dp(s.size()+1, -1);

    dp[s.size()]=1;

    helper(s, wordDict, 0, dp);

    return dp[0];
  }
};

//DFS Solution with O(m^n time complexity)
class Solution3 {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return dfs(s, wordDict, 0);
  }

private:
  bool dfs(const string& s, const vector<string>& wordDict, int i) {
    if (i == s.length()) {
      return true;
    }

    for (const string& w : wordDict) {
      if (i + w.length() <= s.length() &&
          s.substr(i, w.length()) == w) {
        if (dfs(s, wordDict, i + w.length())) {
          return true;
        }
      }
    }
    return false;
  }
};
