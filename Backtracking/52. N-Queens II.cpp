//
// Created by Suhas Reddy on 2/20/25.
//

//Similar to N-Queens, get the count here instead.
class Solution
{
public:
  unordered_set<int> col_set, posDiag, negDiag;

  int helper(int n, int row, vector<string>&board)
  {
    int count=0;
    if(row==n)
      return 1;

    for(int col=0;col<n; col++)
    {
      if(!col_set.count(col) && !posDiag.count(row+col) && !negDiag.count(row-col))
      {
        col_set.insert(col);
        posDiag.insert(row+col);
        negDiag.insert(row-col);

        board[row][col]='Q';
        count+=helper(n, row+1, board);

        //backtrack
        col_set.erase(col);
        posDiag.erase(row+col);
        negDiag.erase(row-col);
        board[row][col]='.';
      }
    }
    return count;
  }

  int totalNQueens(int n)
  {
    vector<string> board(n, string(n,'.'));

    return helper(n, 0, board);
  }
};