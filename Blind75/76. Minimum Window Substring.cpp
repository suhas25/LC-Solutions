//
// Created by Suhas Reddy on 2/15/25.
//


//Maintain a map of frequency of characters of substring.
// Then we need to match the formed_size to determine if we found the string which matches character count.
class Solution {
public:

  struct result
  {
    int start;
    int end;
    int min_length;
  };

  string minWindow(string s, string t)
  {
    if(t.size()>s.size())
      return "";

    result res(-1, -1, INT_MAX);

    unordered_map<char, int>m1, m2;

    for(auto ch:t)
      m1[ch]++;

    int left=0, right=0;

    int expected_size=m1.size();

    int formed_size=0;

    while(right<s.size())
    {
      m2[s[right]]++;

      if(m1.find(s[right])!=m1.end() && m2[s[right]]==m1[s[right]])
        formed_size++;

      while(left<=right && expected_size==formed_size)
      {
        if(right-left+1<res.min_length)
        {
          res.min_length= right-left+1;
          res.start=left;
          res.end=right;
        }

        if(--m2[s[left]]==0)
          m2.erase(s[left]);

        if(m1.find(s[left])!=m1.end() && m1[s[left]]>m2[s[left]])
          formed_size--;

        left++;
      }

      right++;
    }

    if(res.start==-1)
      return "";
    else
      return s.substr(res.start, res.min_length);
  }
};
