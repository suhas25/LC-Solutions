//
// Created by Suhas Reddy on 2/19/25.
//

// similar to IP Address problem
//O(n*2^n) time complexity and O(n) space complexity for recursion stack

class Solution
{
public:
  vector<vector<string>> result;

  bool is_palindrome(string& s, int start, int end)
  {
    while(start<end)
    {
      if(s[start]!=s[end])
        return false;
      start++, end--;
    }
    return true;
  }

  void helper(string&s, vector<string>& curr_vector, int index)
  {
    if(index==s.size())
    {
      result.push_back(curr_vector);
      return;
    }

    for(int i=index; i<s.size(); i++)
    {
      if(is_palindrome(s, index, i))
      {
        curr_vector.emplace_back(s.substr(index, i-index+1));
        helper(s, curr_vector, i+1);

        //backtracking
        curr_vector.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s)
  {
    vector<string>temp;
    helper(s, temp, 0);

    return result;
  }
};