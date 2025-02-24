//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  int calPoints(vector<string>& operations)
  {
    stack<string>stk;

    for(auto operation:operations)
    {
      if(operation=="C")
      {
        stk.pop();
      }
      else if(operation=="D")
      {
        auto ele1=stk.top();
        stk.push(to_string(stoi(ele1)*2));
      }
      else if(operation=="+")
      {
        auto ele1=stk.top();stk.pop();
        auto ele2=stk.top();stk.pop();
        auto sum = stoi(ele1)+stoi(ele2);

        stk.push(ele2), stk.push(ele1);
        stk.push(to_string(sum));
      }
      else
      {
        stk.push(operation);
      }
    }

    int points=0;
    while(!stk.empty())
    {
      points+=stoi(stk.top());
      stk.pop();
    }

    return points;
  }
};
