//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    vector<int>result(k);
    unordered_map<int,int>m;

    for(auto num:nums)
      m[num]+=1;

    std::function<bool(pair<int,int>&, pair<int,int>&)> customcompare = [](pair<int, int> &a, pair<int, int> &b){
      return a.second>b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(customcompare)>pq(customcompare);

    for(auto num:m)
    {
      pq.push(make_pair(num.first, num.second));
      if(pq.size()>k)
        pq.pop();
    }


    for(int i=0;i<k; i++)
    {
      auto element = pq.top();
      pq.pop();
      result[k-i-1]= element.first;
      cout<<element.first<< " "<<element.second<<endl;
    }

    return result;
  }
};