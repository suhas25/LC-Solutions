//
// Created by Suhas Reddy on 2/15/25.
//

class Solution
{
public:

  bool helper(std::vector<std::vector<char>>& board, std::string word, int index, int i, int j)
  {
    //base case
    if(index==word.size())
      return true;

    //edge case
    if(i<0 ||i>=board.size() || j<0 ||j>=board[0].size())
      return false;


    if(board[i][j]==word[index])
    {
      char ch = board[i][j];
      board[i][j]='#';
      if(helper(board, word, index+1, i+1, j)||
          helper(board, word, index+1, i, j+1) ||
          helper(board, word, index+1, i-1, j) ||
          helper(board, word, index+1, i, j-1))
      {
        return true;
      }

      board[i][j]=ch;
    }
    return false;


  }

  bool exist(std::vector<std::vector<char>>& board, std::string word)
  {
    for(int i=0;i<board.size(); i++)
    {
      for(int j=0;j<board[0].size(); j++)
      {
        if(helper(board, word, 0, i, j))
        {
          return true;
        }
      }
    }

    return false;
  }
};