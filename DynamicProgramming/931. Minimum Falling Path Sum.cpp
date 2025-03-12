//
// Created by Suhas Reddy on 3/9/25.
//

//O(rows*cols) time and space complexity
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix)
  {
    int rows = matrix.size(), cols = matrix[0].size();

    vector<vector<int>>dp(rows, vector<int>(cols, INT_MAX));

    for(int col=0;col<cols; col++)
      dp[0][col]=matrix[0][col];

    for(int row=1;row<rows; row++)
    {
      for(int col=0;col<cols; col++)
      {
        if(col==0)
          dp[row][col]= matrix[row][col]+min({dp[row-1][col], dp[row-1][col+1]});
        else if(col==cols-1)
          dp[row][col]= matrix[row][col]+min({dp[row-1][col], dp[row-1][col-1]});
        else
          dp[row][col]= matrix[row][col]+ min({dp[row-1][col], dp[row-1][col-1], dp[row-1][col+1]});
      }
    }

    int result_sum=INT_MAX;

    for(auto val:dp[rows-1])
      result_sum=min(val, result_sum);

    return result_sum;
  }
};
