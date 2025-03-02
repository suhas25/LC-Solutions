//
// Created by Suhas Reddy on 2/25/25.
//

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    if(ransomNote.size()>magazine.size())
      return false;

    unordered_map<char, int>magazine_freq;

    for(const auto& ch:magazine)
      magazine_freq[ch]++;

    for(const auto& ch:ransomNote)
    {
      if(magazine_freq.find(ch)==magazine_freq.end())
        return false;
      if(--magazine_freq[ch]==0)
        magazine_freq.erase(ch);
    }

    return true;
  }
};
