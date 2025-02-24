//
// Created by Suhas Reddy on 2/22/25.
//
//DP with O(n) time and space complexity.

class Solution {
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>>result;

    vector<int>temp(1, 1);
    result.push_back(temp);

    for(int i=1;i<numRows; i++)
    {
      vector<int>row(i+1, 1);
      auto prev_row = result[i-1];

      for(int j=1;j<i; j++)
      {
        row[j]=(prev_row[j-1]+ prev_row[j]);
      }
      result.push_back(row);
    }
    return result;
  }
};