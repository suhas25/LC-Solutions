//
// Created by Suhas Reddy on 2/19/25.
//

/*
* - Insert row by row iterating through all the columns in row.
 */

//O(n!) time complexity
class Solution
{
public:
  vector<vector<string>>result;

  bool is_safe(int row, int col, vector<string>&board)
  {
    // check along current col in prev rows.
    for(int i=0;i<row; i++)
      if(board[i][col]=='Q')
        return false;

    //check along that diagonal
    for(int i=row, j=col;i>=0 && j<board.size(); i--, j++)
      if(board[i][j]=='Q')
        return false;

    //check along that anti-diagonal
    for(int i=row, j=col;i>=0 && j>=0; i--, j--)
      if(board[i][j]=='Q')
        return false;

    return true;
  }

  void helper(int n, int row, vector<string>&board)
  {
    if(row==n)
    {
      result.push_back(board);
      return;
    }

    for(int col=0;col<n; col++)
    {
      if(is_safe(row, col, board))
      {
        board[row][col]='Q';
        helper(n, row+1, board);
        board[row][col]='.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {
    vector<string> board(n, string(n,'.'));
    helper(n, 0, board);

    return result;
  }
};


/*
* - Optimizating using sets of col, positive and negative diagonal.
 */
class Solution2
{
public:
  vector<vector<string>>result;
  unordered_set<int> col_set, posDiag, negDiag;

  void helper(int n, int row, vector<string>&board)
  {
    if(row==n)
    {
      result.push_back(board);
      return;
    }

    for(int col=0;col<n; col++)
    {
      if(!col_set.count(col) && !posDiag.count(row+col) && !negDiag.count(row-col))
      {
        col_set.insert(col);
        posDiag.insert(row+col);
        negDiag.insert(row-col);

        board[row][col]='Q';
        helper(n, row+1, board);

        //backtrack
        col_set.erase(col);
        posDiag.erase(row+col);
        negDiag.erase(row-col);
        board[row][col]='.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {
    vector<string> board(n, string(n,'.'));
    helper(n, 0, board);

    return result;
  }
};