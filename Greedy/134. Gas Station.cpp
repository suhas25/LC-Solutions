//
// Created by Suhas Reddy on 2/23/25.
//

//O(n) time complexity and O(1) space complexity.

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
  {
    int curr_gain=0, total_gain=0;
    int result_index=0;

    for(int i=0;i<gas.size(); i++)
    {
      total_gain+=gas[i]-cost[i];
      curr_gain+=gas[i]-cost[i];

      if(curr_gain<0)
      {
        result_index=i+1;
        curr_gain=0;
      }
    }
    return (total_gain>=0)?result_index: -1;
  }
};