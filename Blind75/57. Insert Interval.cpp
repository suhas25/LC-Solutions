//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // If the intervals vector is empty, return a vector containing the
    // newInterval
    if (intervals.empty()) {
      return {newInterval};
    }

    int n = intervals.size();
    int target = newInterval[0];
    int left = 0, right = n;

    // Binary search to find the position to insert newInterval
    while (left <right)
    {
      int mid = (left + right) / 2;
      if (intervals[mid][0] < target)
      {
        left = mid + 1;
      }
      else
        right = mid;
    }

    // Insert newInterval at the found position
    intervals.insert(intervals.begin() + left, newInterval);

    // Merge overlapping intervals
    vector<vector<int>> res;
    for (const auto& interval : intervals)
    {
      if (res.empty() || res.back()[1] < interval[0])
        res.push_back(interval);
      else
        res.back()[1] = max(res.back()[1], interval[1]);
    }

    return res;
  }
};
