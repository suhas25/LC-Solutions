//
// Created by Suhas Reddy on 2/15/25.
//

/*
 * 1. Form Trie using the words
 * 2. Do a bfs starting at every cell looking for words in matrix
 * 3. use string word in trienode to store word in the last node.
 */

struct TrieNode
{
  char ch;
  string word = "";
  TrieNode(char ch) : ch(ch) {};
  unordered_map<char, TrieNode*> children;
};

class Solution
{
public:
  vector<string> result;

  void helper(vector<vector<char>>& board, TrieNode* node, int i, int j)
  {
    if(node->word!="")
    {
      result.push_back(node->word);
      node->word = ""; // to eliminate duplicates
    }
    //base cases
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
      return;

    if(node->children.count(board[i][j]))
    {
      auto temp = board[i][j];

      auto child_node = node->children[board[i][j]];

      board[i][j]='#';

      helper(board, child_node, i+1, j);
      helper(board, child_node, i, j+1);
      helper(board, child_node, i-1, j);
      helper(board, child_node, i, j-1);

      board[i][j]=temp;
    }
  }

  vector<string> findWords(vector<vector<char>>& board,
                           vector<string>& words)
  {
    TrieNode* root = new TrieNode('#');

    for (const auto& word : words)
    {
      auto node = root;
      for (char ch : word)
      {
        // create new node
        if (node->children.find(ch) == node->children.end())
        {
          TrieNode* newnode = new TrieNode(ch);
          node->children[ch] = newnode;
        }
        node = node->children[ch];
      }
      node->word = word; // important to mark the word
    }

    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[0].size(); j++)
      {
        if (root->children.find(board[i][j]) != root->children.end())
          helper(board, root, i, j);
      }
    }
    return result;
  }
};
