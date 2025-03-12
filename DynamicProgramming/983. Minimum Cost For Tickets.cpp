//
// Created by Suhas Reddy on 3/8/25.
//

//O(365) time and space complexity
class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs)
  {
    int last_day = days[days.size()-1];

    vector<int>dp(last_day+1, 0);

    int curr_index=0;
    for(int day=1;day<=last_day; day++)
    {
      if(day<days[curr_index])
        dp[day]=dp[day-1];
      else
      {
        dp[day]=min({dp[day-1]+costs[0], dp[max(0, day-7)]+costs[1], dp[max(0, day-30)]+costs[2]});
        curr_index++;
      }
    }
    return dp[last_day];
  }
};