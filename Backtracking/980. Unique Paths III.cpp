//
// Created by Suhas Reddy on 2/15/25.
//

/*
 * we need backtracking and dp wont work because
 * we need to travel to every valid square.
 * */

class Solution
{
public:

  int helper(int r, int c, vector<vector<int>>& grid, int remaining_squares)
  {
    //edge cases
    if(r>=grid.size() || c>=grid[0].size() || grid[r][c]==-1 ||grid[r][c]==4)
      return 0;

    //base case
    if(grid[r][c]==2)
    {
      if(remaining_squares==1)
        return 1;
      return 0;
    }

    remaining_squares--;

    auto temp = grid[r][c];
    grid[r][c]=4; //marking as visited

    int result = helper(r+1, c, grid, remaining_squares)+
                 helper(r-1, c, grid, remaining_squares)+
                 helper(r, c+1, grid, remaining_squares)+
                 helper(r, c-1, grid, remaining_squares);

    grid[r][c]=temp;

    return result;
  }

  int uniquePathsIII(vector<vector<int>>& grid)
  {
    int start_row, start_col;

    //dp wont work here because starting everynode, u will have to traverse all the nodes in matrix.
    int valid_squares=0; //need it to satisfy condition where all squares are traversed.

    for(int i=0;i<grid.size(); i++)
    {
      for(int j=0;j<grid[0].size(); j++)
      {
        if(grid[i][j]==1)
        {
          start_row=i;
          start_col=j;
        }

        if(grid[i][j]!=-1)
          valid_squares++;
      }
    }

    return helper(start_row, start_col, grid, valid_squares);
  }
};