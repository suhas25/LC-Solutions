//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  string removeDuplicates(string s)
  {
    vector<char>stk;

    for(int i=0;i<s.size(); i++)
    {
      if(!stk.empty() && stk.back()==s[i])
      {
        stk.pop_back();
      }
      else
        stk.push_back(s[i]);
    }

    string result;
    for(auto ch:stk)
      result+=ch;

    return result;
  }
};
