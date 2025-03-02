//
// Created by Suhas Reddy on 2/25/25.
//

/*
 * we are calculating the ma_length of square considering the right bottom square at every given point
 * based on the other 3 squares above it.
 *
 * O(m*n) time and space complexity.
 * */

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix)
  {
    int rows = matrix.size(), cols = matrix[0].size();

    vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));

    int max_length=0;

    for(int i=1;i<=rows; i++)
    {
      for(int j=1; j<=cols; j++)
      {
        if(matrix[i-1][j-1]=='1')
        {
          dp[i][j]= 1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));

          max_length=max(max_length, dp[i][j]);
        }
      }
    }
    return max_length*max_length;
  }
};

//O(m*n) time and O(n) space complexity.
class Solution2
{
  public:
  int maximalSquare(vector<vector<char>>& matrix)
    {
      int rows = matrix.size();
      int cols = rows > 0 ? matrix[0].size() : 0;
      vector<int> dp(cols + 1, 0);
      int maxsqlen = 0, prev = 0;

      for (int i = 1; i <= rows; ++i)
      {
        for (int j = 1; j <= cols; ++j)
        {
          int temp = dp[j];
          if (matrix[i - 1][j - 1] == '1')
          {
            dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
            maxsqlen = max(maxsqlen, dp[j]);
          }
          prev = temp;
        }
      }
    return maxsqlen * maxsqlen;
  }
};