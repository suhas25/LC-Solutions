//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  vector<vector<char>> boards;
  int n, subgridsize;

  unordered_map<int, unordered_set<int>>rows, cols;

  map<pair<int, int>, unordered_set<int>> box;
  bool solved= false;

  void place_number(int r, int c, int number)
  {
    rows[r].insert(number);
    cols[c].insert(number);
    box[{r/subgridsize, c/subgridsize}].insert(number);
    boards[r][c]=number+'0';
  }

  void remove_number(int r, int c, int number)
  {
    rows[r].erase(number);
    cols[c].erase(number);
    box[{r/subgridsize, c/subgridsize}].erase(number);
    boards[r][c]='.';
  }

  bool is_valid(int r, int c, int number)
  {
    return (rows[r].count(number)+ cols[c].count(number)+box[{r/subgridsize, c/subgridsize}].count(number)==0);
  }

  void helper(int row, int col)
  {
    if(row==n)
    {
      solved = true;
      return;
    }

    if(boards[row][col]=='.')
    {
      for(int i=1;i<=9; i++)
      {
        if(is_valid(row, col, i))
        {
          place_number(row, col, i);
          if(col==n-1)
            helper(row+1, 0);
          else
            helper(row, col+1);

          if(!solved)
            remove_number(row, col, i);
        }
      }
    }

    else
    {
      if(col==n-1)
        helper(row+1, 0);
      else
        helper(row, col+1);
    }
  }

  void solveSudoku(vector<vector<char>>& board)
  {
    this->boards=board;
    n = board.size();
    subgridsize = sqrt(n);

    for(int r=0;r<board.size(); r++)
    {
      for(int c=0;c<board[0].size(); c++)
      {
        if(board[r][c]!='.')
        {
          int number = board[r][c]-'0';
          place_number(r, c, number);
        }
      }
    }

    helper(0, 0);
    board = this->boards;
  }
};