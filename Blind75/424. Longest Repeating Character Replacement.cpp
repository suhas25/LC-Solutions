//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  int characterReplacement(string s, int k) {
    int left=0, right=0;

    unordered_map<char, int>map;

    int result=0;
    int max_freq=0;

    while(right<s.size())
    {
      map[s[right]]++;
      max_freq=max(max_freq,map[s[right]]);

      while(right-left+1>max_freq+k)
      {
        if(--map[s[left]]==0)
          map.erase(s[left]);
        left++;
      }
      result = max(result, right-left+1);
      right++;
    }

    return result;
  }
};
