//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  stack<string>stk;
  int calculate(string s)
  {
    stack<int>stk;
    int result=0;
    int prev_sign = 1;
    long long curr_number=0;

    for(int i=0;i<s.size(); i++)
    {
      char ch = s[i];
      if(isdigit(ch))
      {
        curr_number=curr_number*10+ch-'0';
      }
      else
      {
        if(ch=='+')
        {
          result+=prev_sign* curr_number;
          prev_sign = 1;
          curr_number=0;
        }
        else if(ch=='-')
        {
          result+=prev_sign* curr_number;
          prev_sign = -1;
          curr_number=0;
        }
        else if(ch=='(')
        {
          stk.push(result);
          stk.push(prev_sign);

          //reset values
          prev_sign=1, result=0, curr_number=0;
        }
        else if(ch==')')
        {
          result+=prev_sign*curr_number;

          auto sign = stk.top(); stk.pop();
          auto res=stk.top(); stk.pop();

          result=result*sign+res;
          curr_number=0;
        }
      }
    }
    result+=prev_sign*curr_number;
    return result;
  }
};