//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs)
  {
    unordered_map<string, vector<string>>map;
    vector<vector<string>>result;

    for(auto str:strs)
    {
      int count[26]={0};
      for(auto ch:str)
      {
        count[ch-'a']++;
      }

      string res="";
      for(int i=0;i<26; i++)
      {
        res+='#'+to_string(count[i]);
      }

      map[res].push_back(str);
    }

    for(auto [keys, anagrams]:map)
      result.push_back(anagrams);

    return result;
  }
};
