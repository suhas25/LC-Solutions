//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  stack<int>stk;
  int evalRPN(vector<string>& tokens)
  {
    for(auto token:tokens)
    {
      if(token.size()>1|| isdigit(token[0])) //isdigit check to make sure its not a symbol
      {
        stk.push(stoi(token));
      }
      else // pop when we encounter a symbol  (+, -, /, *)
      {
        int num1 = stk.top(); stk.pop();
        int num2 = stk.top();stk.pop();

        if(token=="+")
          stk.push(num1+num2);
        else if(token=="-")
          stk.push(num2-num1);
        else if(token=="*")
          stk.push(num1*num2);
        else
          stk.push(num2/num1);
      }
    }
    return stk.top();
  }
};
