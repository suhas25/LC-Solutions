//
// Created by Suhas Reddy on 2/21/25.
//

/*
 * Iterate from left to right and push them into stack.
 * while pushing pop all elements greater than element being inserted into stack maintaining count k.
 *
 * */

class Solution {
public:
  string removeKdigits(string num, int k)
  {
    stack<char>stk;
    for(auto ch:num)
    {
      while(!stk.empty() && stk.top()>ch && k>0)
      {
        stk.pop();
        k--;
      }

      stk.push(ch);
    }

    if(k)
    {
      while(k--)
        stk.pop();
    }

    //prepare result.
    string result = "";
    while(!stk.empty())
    {
      result+=stk.top();
      stk.pop();
    }
    reverse(result.begin(), result.end());

    //remove the starting "0" digits encountered before first non zero digit
    int i = 0;
    while (result[i] == '0')
      i++;
    result.erase(0, i);

    if(result=="" )
      return result="0";
    return result;
  }
};
