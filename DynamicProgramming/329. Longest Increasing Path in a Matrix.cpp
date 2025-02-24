//
// Created by Suhas Reddy on 2/24/25.
//

class Solution
{
public:
  int helper(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>&dp)
  {
    if(dp[row][col]!=-1)
      return dp[row][col];

    vector<vector<int>>dirs={{0, -1}, {0, 1}, {1,0}, {-1,0}};

    int count=0;

    for(auto dir:dirs)
    {
      int x = row + dir[0];
      int y = col + dir[1];

      if(x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size() && matrix[x][y]>matrix[row][col])
      {
        count = max(count, helper(matrix, x, y, dp));
      }
    }
    return dp[row][col]=count+1;
  }

  int longestIncreasingPath(vector<vector<int>>& matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>>dp(rows, vector<int>(cols, -1));

    int result=0;

    for(int i=0;i<rows; i++)
    {
      for(int j=0;j<cols; j++)
      {
        result = max(result, helper(matrix, i, j, dp));
      }
    }
    return result;
  }
};