//
// Created by Suhas Reddy on 2/19/25.
//

//O(3^n or 3^12) time complexity as we have to choose position to insert a dot within 3 digits (valid numbers 0-255).


class Solution
{
public:
  vector<string>result;

  void helper(string&s, string curr_string, int index, int dots_so_far)
  {
    if(index==s.size() && dots_so_far==4)
    {
      result.push_back(curr_string.substr(0, curr_string.size()-1));
      return;
    }

    if(dots_so_far>4 || index>=s.size())
      return;

    auto end_index = min(index+3, (int)s.size());

    for(int i=index;i<end_index; i++)
    {
      /*
      check for valid substring using 2 conditions
      1. 0<=num<=255
      2. cant be multiple zeroes like 00.
      */
      if(stoi(s.substr(index, i-index+1))<=255 && ((index==i) || s[index]!='0'))
      {
        helper(s, curr_string+s.substr(index, i-index+1)+".", i+1,dots_so_far+1);
      }
    }
  }

  vector<string> restoreIpAddresses(string s)
  {
    if(s.size()>12)
      return {};

    string curr_string;
    helper(s,curr_string, 0, 0);

    return result;
  }
};