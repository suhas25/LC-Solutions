//
// Created by Suhas Reddy on 2/15/25.
//

//Memoization with 0(n) time and space complexity
class Solution {
public:

  int helper(string& s, int index, unordered_map<int, int>&dp)
  {
    if(dp.count(index))
      return dp[index];

    if(s[index]=='0')
      return 0;

    if(index>=s.size()-1)
      return 1;

    int count = helper(s, index+1, dp);

    if(stoi(s.substr(index, 2))<=26)
      count+=helper(s, index+2, dp);

    dp[index]=count;
    return count;
  }

  int numDecodings(string s)
  {
    unordered_map<int, int>dp; //mapping of index->count
    return helper(s, 0, dp);
  }
};

//DP with O(1) memory and O(N) time complexity
class Solution2 {
public:
  int numDecodings(string s)
  {
    if (s[0] == '0')
      return 0;

    int n = s.length();
    int two_back = 1;
    int one_back = 1;

    for (size_t i = 1; i < n; i++)
    {
      int current = 0;

      //if current index i is "0", then its a invalid decode. so, we cannot pick anything upto index i-1 and add to it.
      if (s[i] != '0')
      {
        current = one_back;
      }

      int two_digit = stoi(s.substr(i - 1, 2));
      if (two_digit >= 10 and two_digit <= 26)
        current += two_back;

      two_back = one_back;
      one_back = current;
    }
    return one_back;
  }
};