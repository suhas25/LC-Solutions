//
// Created by Suhas Reddy on 2/21/25.
//

// maintain a stack of element+counter. Pop if counter matches k.
class Solution {
public:
  string removeDuplicates(string s, int k)
  {
    //{char->count}
    stack<pair<char, int>>stk;

    for(auto ch:s)
    {
      if(!stk.empty() && stk.top().first==ch)
        stk.top().second++;
      else
        stk.push({ch,1});

      if(stk.top().second==k)
        stk.pop();
    }

    string result;
    while(!stk.empty())
    {
      auto [ch, count]=stk.top(); stk.pop();
      while(count--)
        result+=ch;
    }

    reverse(result.begin(), result.end());
    return result;
  }
};