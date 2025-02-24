//
// Created by Suhas Reddy on 2/20/25.
//

//Similar to palindrome partitioning and letters on phone number. O(n*2^N)

class Solution {
public:
  vector<string>result;

  void helper(string& s, unordered_set<string>& wordSet, int index, string curr_string)
  {
    if(index>=s.size())
    {
      result.push_back(curr_string.substr(0, curr_string.size()-1));
      return;
    }

    for(int i=index; i<s.size(); i++)
    {
      auto word=s.substr(index, i-index+1);
      if(wordSet.count(word))
      {
        helper(s, wordSet, i+1, curr_string+word+" ");
      }
    }
  }

  vector<string> wordBreak(string s, vector<string>& wordDict)
  {
    string curr_string;
    unordered_set<string>wordSet(wordDict.begin(), wordDict.end());

    helper(s, wordSet, 0, curr_string);

    return result;
  }
};
