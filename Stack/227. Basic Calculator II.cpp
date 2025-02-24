//
// Created by Suhas Reddy on 2/21/25.
//
/**
 * Four rules
 * by default take previous sign = "+".
 * we always act based on prev sign and update prev sign and curr_value after the iteration.
 * 1. when prev sign is + or - (push +value or -value) into stack
 * 2. when prev sign is * or / (Calculate stk.top()* currnumber_ and push into stack
 * 3. make sure to handle white spaces and when len==n-1;
 *
 */

class Solution {
public:
  int calculate(string s)
  {
    char prev_sign = '+';
    long long curr_number=0;
    stack<int>stk;
    int result=0;

    for(int i=0;i<s.size(); i++)
    {
      char ch = s[i];
      if(isdigit(ch))
      {
        curr_number=curr_number*10+ch-'0';
      }

      if((!iswspace(ch) && !isdigit(ch)) || i==s.size()-1)
      {
        if(prev_sign=='+')
          stk.push(curr_number);
        if(prev_sign=='-')
          stk.push(-curr_number);
        if(prev_sign=='*')
        {
          auto num = stk.top(); stk.pop();
          stk.push(num*curr_number);
        }
        if(prev_sign=='/')
        {
          auto num = stk.top(); stk.pop();
          stk.push(num/curr_number);
        }

        //update sign and reset number.
        prev_sign=ch;
        curr_number=0;
      }
    }

    while(!stk.empty())
    {
      result+=stk.top();
      stk.pop();
    }
    return result;
  }
};

//without using stack and storing values in result.
//logic similar to stack solution above.
class Solution2 {
public:
  int calculate(string s) {
    int length = s.length();
    if (length == 0) return 0;
    int currentNumber = 0, lastNumber = 0, result = 0;
    char prev_sign = '+';
    for (int i = 0; i < length; i++)
    {
      char ch = s[i];
      if (isdigit(ch))
      {
        currentNumber = (currentNumber * 10) + (ch - '0');
      }

      if (!isdigit(ch) && !iswspace(ch) || i == length - 1)
      {
        if (prev_sign == '+' || prev_sign == '-')
        {
          result += lastNumber;
          lastNumber = (prev_sign == '+') ? currentNumber : -currentNumber;
        }
        else if (prev_sign == '*')
          lastNumber = lastNumber * currentNumber;
        else if (prev_sign == '/')
          lastNumber = lastNumber / currentNumber;

        prev_sign = ch;
        currentNumber = 0;
      }
    }
    result += lastNumber;
    return result;
  }
};