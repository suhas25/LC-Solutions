//
// Created by Suhas Reddy on 2/15/25.
//



//greedy approach -> sort by interval start times and add count( interval to be removed) when they overlap.
class Solution
{
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
      auto cmp =[](vector<int>&a, vector<int>&b)
      {
        return a[1]<b[1];
      };

      sort(intervals.begin(), intervals.end(), cmp);

      int count = 0;
      int current_end=intervals[0][1];

      for(int i=1; i<intervals.size(); i++)
      {
        auto start=intervals[i][0];
        auto end=intervals[i][1];

        if(start>=current_end)
          current_end=end;
        else //overlapping case
        {
          count++;
          current_end= min(current_end, end); //pick the one which ends first
        }
      }
      return count;
    }
};