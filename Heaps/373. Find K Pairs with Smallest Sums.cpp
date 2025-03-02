//
// Created by Suhas Reddy on 2/25/25.
//

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
  {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>>result;

    //pq -> {sum, {index1, index2}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    struct PairHash{
      size_t operator()(const pair<int, int>&a) const
      {
        return std::hash<int>()(a.first) ^ (std::hash<int>() (a.second << 1));
      }
    };

    struct PairEqual{
      bool operator()(const pair<int, int>&a, const pair<int, int>&b) const
      {
        return a.first==b.first && a.second==b.second;
      }
    };


    //easiest is to use ordered_map instead of unordered_map.
    unordered_set<pair<int,int>, PairHash, PairEqual>visited;
    visited.insert({0, 0});
    pq.push({nums1[0]+nums2[0], {0,0}});

    while(k-- && !pq.empty())
    {
      auto [x, y]=pq.top();pq.pop();

      result.push_back({nums1[y.first], nums2[y.second]});

      if(y.first<m-1 && visited.find({y.first+1, y.second})==visited.end())
      {
        pq.push({nums1[y.first+1]+nums2[y.second], {y.first+1, y.second}});
        visited.insert({y.first+1, y.second});
      }

      if(y.second<n-1 && visited.find({y.first, y.second+1})==visited.end())
      {
        pq.push({nums1[y.first]+nums2[y.second+1], {y.first, y.second+1}});
        visited.insert({y.first, y.second+1});
      }
    }

    return result;
  }
};
