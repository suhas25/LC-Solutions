//
// Created by Suhas Reddy on 2/24/25.
//

class Solution
{
public:
  struct TrieNode
  {
    TrieNode(char ch):ch(ch){};
    char ch;
    bool is_word=false;
    unordered_map<char, TrieNode*> child;
  };

  class Trie
  {
  public:
    TrieNode* root;
    Trie()
    {
      root=new TrieNode('#');
    }

    void insert(const string& s)
    {
      TrieNode* node = root;
      for(int i=0;i<s.size(); i++)
      {
        char ch = s[i];
        if(!node->child.count(ch))
        {
          TrieNode* newnode = new TrieNode(ch);
          node->child[ch]=newnode;
        }
        node = node->child[ch];
      }
      node->is_word=true;
    }

    bool find(string_view s)
    {
      TrieNode* node = root;
      for(int i=0;i<s.size(); i++)
      {
        char ch = s[i];
        if(node->child.count(ch))
          node = node->child[ch];
        else
          return false;
      }
      return node->is_word;
    }
  };

  int longestValidSubstring(string word, vector<string>& forbidden)
  {
    Trie trie;
    for(const auto& word:forbidden)
    {
      trie.insert(word);
    }

    int left=0, right=0;
    int max_len=0;

    while(right<word.size())
    {
      // we check every substring from right to left and update left accordingly.
      for(int i=right; i>=left; --i)
      {
        if(trie.find(word.substr(i, right-i+1)))
        {
          left=i+1;
          break;
        }
      }
      max_len = max(max_len, right - left + 1);
      ++right;
    }
    return max_len;
  }
};