//
// Created by Suhas Reddy on 2/15/25.
//

class WordDictionary {
public:

  struct TrieNode
  {
    TrieNode(char ch):ch(ch){}
    char ch;
    unordered_map<char, TrieNode*>children;

    bool is_word = false;
  };

  TrieNode* root;
  WordDictionary()
  {
    root = new TrieNode('#');
  }

  void addWord(string word)
  {
    auto node = root;

    for(const auto&ch: word)
    {
      if(!node->children.count(ch))
      {
        TrieNode* newnode = new TrieNode(ch);
        node->children[ch]=newnode;
      }
      node = node->children[ch];
    }
    node->is_word=true;
  }

  bool search_helper(string word, TrieNode* node)
  {
    for(int i=0;i<word.size(); i++)
    {
      char ch = word[i];

      if(node->children.count(ch))
      {
        node = node->children[ch];
      }
      //when node is not found
      else
      {
        if(ch=='.')
        {
          for(auto [_, child_node]:node->children)
          {
            if(search_helper(word.substr(i+1), child_node))
              return true;
          }

          return false;
        }
        //node not found
        else
          return false;
      }

    }
    return node->is_word;
  }

  bool search(string word)
  {
    return search_helper(word, root);
  }
};
