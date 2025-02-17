//
// Created by Suhas Reddy on 2/16/25.
//

//when string is long and we do not want to traverse it twice
//solution 2 is idle when we can traverse strings twice with O(26) space complexity.

class Solution {
public:
  int firstUniqChar(string s)
  {
    // mapping of char -> {count, index}
    unordered_map<char, pair<int, int>> m;

    int result_index = INT_MAX;

    for (int i = 0; i < s.size(); i++)
    {
      m[s[i]].first++;
      m[s[i]].second = i;
    }
    for (const auto& [_, pair] : m)
    {
      if (pair.first == 1)
      {
        result_index = min(result_index, pair.second);
      }
    }
    return result_index == INT_MAX ? -1 : result_index;
  }
};

class Solution2
{
  public:
    int firstUniqChar(string s)
    {
      unordered_map<char, int> m;

      for (char& c : s)
      {
        m[c]++;
      }
      for (int i = 0; i < s.size(); i++)
      {
        if (m[s[i]] == 1) return i;
      }
      return -1;
    }
};


