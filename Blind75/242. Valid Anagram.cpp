//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  bool isAnagram(string s, string t)
  {
    int a[26]={0};

    for(auto ch:s)
      a[ch-'a']++;

    for(auto ch:t)
      a[ch-'a']--;

    for(auto i:a)
      if (i!=0)
        return false;

    return true;
  }
};