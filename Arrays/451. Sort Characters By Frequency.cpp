//
// Created by Suhas Reddy on 2/16/25.
//

//Bucket sort solution with O(n) time complexity

class Solution {
public:
  string frequencySort(string s)
  {
    //mapping of char->counts
    unordered_map<char, int>m;

    auto max_freq=0;
    for(auto ch:s)
    {
      m[ch]++;
      max_freq=max(max_freq, m[ch]);
    }

    vector<string>buckets(max_freq+1, "");

    for(auto [ch, count]:m)
    {
      buckets[count].append(count, ch); //append(count, char)
    }

    string result="";

    for(int i=max_freq;i>=0; i--)
    {
      if(!buckets[i].empty())
        result.append(buckets[i]);
    }

    return result;
  }
};
