//
// Created by Suhas Reddy on 2/19/25.
//

//O(2^2n) time complexity and O(n) space complexity
class Solution
{
public:
  vector<string>result;
  char open='(';
  char close = ')';

  void helper(int length, int open_count, int closed_count, string curr_str)
  {
    //base case
    if(curr_str.length()==length*2)
    {
      result.push_back(curr_str);
      return;
    }

    if(open_count<length)
      helper(length, open_count+1, closed_count, curr_str+"(");

    if(closed_count<open_count)
      helper(length, open_count, closed_count+1, curr_str+")");
  }

  vector<string> generateParenthesis(int n)
  {
    helper(n, 0, 0, "");
    return result;
  }
};