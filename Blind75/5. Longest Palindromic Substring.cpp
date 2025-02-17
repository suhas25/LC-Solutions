//
// Created by Suhas Reddy on 2/16/25.
//

// -> best solution is manachers algo which solves in O(n) time complexity

//Consider every character as center and expand around center. O(n^2) time and O(1) space complexity
// make sure to consider odd and even length palindromes.
class Solution {
public:
  string longestPalindrome(string s)
  {
    int max_length=0;
    string result="";

    //consider each index as center and expand around it.
    for(int i=0;i<s.size(); i++)
    {
      //odd size palindromes
      int left=i, right=i;
      while(left>=0 && right<s.size() && s[left]==s[right])
      {
        if(right-left+1>max_length)
        {
          max_length=right-left+1;
          result=s.substr(left, max_length);
        }
        left--, right++;
      }

      //even size palindromes

      left=i, right=i+1;
      while(left>=0 && right<s.size() && s[left]==s[right])
      {
        if(right-left+1>max_length)
        {
          max_length=right-left+1;
          result=s.substr(left, max_length);
        }
        left--, right++;
      }
    }

    return result;
  }
};


//BruteForce O(n^3).
class Solution3 {
public:
  string longestPalindrome(string s)
  {
    string res = "";
    int resLen = 0;

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i; j < s.size(); j++)
      {
          int l = i, r = j;
          while (l < r && s[l] == s[r])
          {
            l++, r--;
          }

          if (l >= r && resLen < (j - i + 1))
          {
            res = s.substr(i, j - i + 1);
            resLen = j - i + 1;
          }
      }
    }
    return res;
  }
};