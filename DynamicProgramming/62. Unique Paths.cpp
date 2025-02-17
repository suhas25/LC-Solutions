//
// Created by Suhas Reddy on 2/15/25.
//

//O(n) space optimization
class Solution {
public:
  int uniquePaths(int m, int n)
  {
    vector<int> dp(n, 1);
    for(int i = 1; i < m; i++)
      for(int j = 1; j < n; j++)
        dp[j] += dp[j-1];
    return dp[n-1];
  }
};


//Big O(m*n) space complexity solution
class Solution2 {
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>>dp(m, vector<int>(n, 1));

    for(int row=1;row<m; row++)
    {
      for(int col=1;col<n; col++)
      {
        dp[row][col]= dp[row-1][col]+ dp[row][col-1];
      }
    }

    return dp[m-1][n-1];
  }
};


class Solution3 {
public:
  int helper(int r, int c, int m, int n, vector<vector<int>>&board)
  {
    if(r==m-1 && c==n-1)
      return 1;

    if(r>=m || c>=n)
      return 0;

    if(board[r][c]!=-1)
      return board[r][c];

    int down = helper(r+1, c, m, n, board);
    int right = helper(r, c+1, m, n, board);

    board[r][c]= right+down;
    return right+down;
  }
  int uniquePaths(int m, int n)
  {
    vector<vector<int>>board(m, vector<int>(n, -1));
    return helper(0, 0, m, n, board);
  }
};
