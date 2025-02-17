//
// Created by Suhas Reddy on 2/16/25.
//

//Expanding around center -> O(n^2) time complexity.
class Solution
{
public:
  /*can be done in 2 ways
      1. DP
      2. Expland around centre with two cases (i,i)[odd] and (i, i+1)[even] over length (i=0->n-1)
  */

  int helper(string s, int left, int right)
  {
    int count=0;
    while(left>=0 && right<s.size() && s[left]==s[right])
    {
      left--, right++, count++;
    }

    return (count>0)?count:0;
  }

  int countSubstrings(string s)
  {
    int count =0;

    for(int i=0; i<s.size(); i++)
    {
      count+=helper(s, i, i); //odd size palindromic substrings.
      count+=helper(s, i, i+1); //even size palindromic substrings
    }

    return count;
  }
};
