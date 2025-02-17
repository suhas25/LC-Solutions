//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:

  // static bool comp(vector<int>&a, vector<int>&b)
  // {
  //         return a[0]<b[0];
  // }

  int minMeetingRooms(vector<vector<int>>& intervals)
  {
    int minimumrooms = 0;
    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, std::greater<int>>pq;

    for(auto interval:intervals)
    {
      if(pq.size()==0 || pq.top()>interval[0])
      {
        pq.push(interval[1]);
        minimumrooms++;
      }
      else
      {
        auto ele = pq.top();
        pq.pop();
        pq.push(interval[1]);
      }
    }

    return minimumrooms;
  }
};
