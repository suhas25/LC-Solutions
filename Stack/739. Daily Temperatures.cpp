//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures)
  {
    vector<int>result;

    //temperature -> index
    stack<pair<int,int>>stk;

    for(int i=temperatures.size()-1; i>=0; i--)
    {
      while(!stk.empty() && stk.top().first<=temperatures[i])
        stk.pop();

      if(stk.empty())
        result.push_back(0);
      else
        result.push_back(stk.top().second-i);
      stk.push({temperatures[i], i});
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
