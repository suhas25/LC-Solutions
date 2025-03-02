//
// Created by Suhas Reddy on 3/2/25.
//

//O(n) time complexity
class Solution {
public:
  string removeDuplicates(string s)
  {
    std::string result;

    for (char ch : s)
    {
      if (result.empty() || result.back() != ch)
        result.push_back(ch);
      else
        result.pop_back();
    }
    return result;
  }
};