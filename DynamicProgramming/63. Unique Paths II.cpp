//
// Created by Suhas Reddy on 2/15/25.
//

//O(m*n) time complexity and O(n) time complexity
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
  {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector<int> dp(col, 0);
    dp[0] = 1;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (obstacleGrid[i][j])
          dp[j] = 0;
        else if (j > 0)
          dp[j] += dp[j - 1];
      }
    }
    return dp[col - 1];
  }
};

class Solution2
{
public:

  int helper(int r, int c, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid)
  {
    if(r==obstacleGrid.size()-1 && c==obstacleGrid[0].size()-1)
      return 1;

    if(r>=obstacleGrid.size() || c>=obstacleGrid[0].size())
      return 0;

    if(dp[r][c]!=-1)
      return dp[r][c];

    if(obstacleGrid[r][c]==1)
    {
      dp[r][c]=0;
      return 0;
    }

    int down = helper(r+1, c, dp, obstacleGrid);
    int right = helper(r, c+1, dp, obstacleGrid);

    dp[r][c]= down+right;
    return down+right;
  }
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
      return 0;

    vector<vector<int>>dp(m, vector<int>(n, -1));
    return helper(0, 0, dp, obstacleGrid);
  }
};
