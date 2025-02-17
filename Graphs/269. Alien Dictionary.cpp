//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  string alienOrder(vector<string>& words)
  {
    unordered_map<char, vector<char>>adjList;
    unordered_map<char, int> indegree_count;

    for(const auto&word:words)
    {
      for(const auto&ch:word)
      {
        adjList[ch]=vector<char>();
        indegree_count[ch]=0;
      }
    }

    for(int i=0;i<words.size()-1; i++)
    {
      auto word1 = words[i];
      auto word2= words[i+1];

      // ex - ab should come before abc, otherwise return false
      if(word1.size()>word2.size() && word1.substr(0, word2.size())==word2)
        return "";

      for(int j=0;j<min(word1.size(), word2.size()); j++)
      {
        //push first non matching character
        if(word1[j]!=word2[j])
        {
          adjList[word1[j]].push_back(word2[j]);
          indegree_count[word2[j]]++;
          break;
        }
      }
    }

    string result="";
    queue<char>q;
    for(auto [ch, count]:indegree_count)
    {
      if(count==0)
        q.push(ch);
    }

    while(!q.empty())
    {
      char ch = q.front();
      q.pop();
      result+=ch;

      for(auto nei:adjList[ch])
      {
        if(--indegree_count[nei]==0)
          q.push(nei);
      }
    }

    if(result.size()==indegree_count.size())
      return result;

    return "";
  }
};

