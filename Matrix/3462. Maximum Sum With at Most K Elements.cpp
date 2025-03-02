//
// Created by Suhas Reddy on 3/2/25.
//

/*
 * Push elements into pq using a pair of {value, row_id}
 * while popping check if we reached row limit and ignore it if exceeded.
 */

//O(rows*cols*log(cols)) time and O(m*n) space complexity
class Solution {
public:
  long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k)
  {
    int rows = grid.size(), cols = grid[0].size();

    auto cmp = [](const pair<int, int>&a, const pair<int, int>&b)
    {
      return b.first>a.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>pq(cmp);

    for(int i=0;i<rows; i++)
    {
      for(int j=0;j<cols; j++)
      {
        pq.push({grid[i][j], i});
      }
    }

    vector<int>row_wise_count(limits);

    long long result=0;
    while(!pq.empty() && k>0)
    {
      auto [ele, row]= pq.top(); pq.pop();

      if(row_wise_count[row]>0)
      {
        result+=ele;
        row_wise_count[row]--;
        k--;
      }
    }
    return result;
  }
};
