//
// Created by Suhas Reddy on 2/15/25.
//

class Solution
{
public:

  /*
  another way is to read and store into map of <char, index>
  then move left to index+1 when it is found while iterating.
  */
  int lengthOfLongestSubstring(string s)
  {
    int left=0, right=0;

    int res=0;
    unordered_set<char> set;

    while(right<s.size())
    {
      char curr_char = s[right];

      if(set.find(curr_char)!=set.end())
      {
        while(left<=right)
        {
          char curr = s[left];
          set.erase(curr);
          left++;

          if(curr==curr_char)
            break;
        }
      }
      else
      {
        res = max(res, right-left+1);
      }
      set.insert(curr_char);
      ++right;
    }
    return res;
  }
};