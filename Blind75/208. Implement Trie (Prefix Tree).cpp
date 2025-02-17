//
// Created by Suhas Reddy on 2/15/25.
//

class Trie
{
  public:
    struct TrieNode
    {
      char ch;
      TrieNode(char ch):ch(ch){}

      unordered_map<char, TrieNode*> children;
      bool is_word = false;
    };

    TrieNode* root;

    Trie()
    {
      root = new TrieNode('#');
    }

    void insert(string word)
    {
      auto node = root;
      for(const auto &ch:word)
      {
        if(! node->children.count(ch))
        {
          TrieNode* newNode = new TrieNode(ch);
          node->children[ch]=newNode;
        }

        node = node->children[ch];
      }

      node-> is_word = true;
    }

    bool search(string word)
    {
      auto node = root;
      for(const auto &ch:word)
      {
        if(!node->children.count(ch))
          return false;

        node = node->children[ch];
      }

      return (node->is_word == true);

    }

    bool startsWith(string prefix)
    {
      auto node = root;
      for(const auto &ch:prefix)
      {
        if(!node->children.count(ch))
          return false;

        node = node->children[ch];
      }

      return true;
    }
};

class Trie2
{
  public:

    struct TrieNode
    {
      char c;
      TrieNode(char ch):c(ch){}
      bool word=false;
      unordered_map<char, TrieNode*> child;
    };

    TrieNode* root;
    Trie() {
      root = new TrieNode('#');
    }

    void insert(string word)
    {
      TrieNode* node = root;
      for(auto ch:word)
      {
        if(node->child.find(ch)==node->child.end())
        {
          TrieNode* newnode = new TrieNode(ch);
          node->child[ch]=newnode;
        }
        node = node->child[ch];
      }
      node->word=true;
    }

    bool search(string word)
    {
      TrieNode* node = root;
      for(auto ch:word)
      {
        if(node->child.find(ch)==node->child.end())
          return false;
        node = node->child[ch];
      }
      return node->word;
    }

    bool startsWith(string prefix)
    {
      TrieNode* node = root;
      for(auto ch:prefix)
      {
        if(node->child.find(ch)==node->child.end())
          return false;
        node = node->child[ch];
      }
      return true;
    }
};
