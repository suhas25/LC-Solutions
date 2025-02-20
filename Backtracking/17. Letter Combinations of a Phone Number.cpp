//
// Created by Suhas Reddy on 2/19/25.
//

class Solution
{
  public:
  vector<string>result;

  void permute(string digits, unordered_map<int, string>m, int index, string res)
  {
    //base case
    if(digits.size()==index)
    {
      result.push_back(res);
      return;
    }

    for(char ch: m[digits[index]-'0'])
    {
      res+=ch;
      permute(digits,m, index+1, res);
      res.pop_back();
    }
  }

  vector<string> letterCombinations(string digits)
  {
    if(digits.size()==0)
      return {};

    unordered_map<int, string> m;
    m.insert({2, "abc"});
    m[3]={"def"};
    m[4]={"ghi"};
    m[5]={"jkl"};
    m[6]={"mno"};
    m[7]={"pqrs"};
    m[8]={"tuv"};
    m[9]={"wxyz"};

    string curr_str;
    permute(digits, m, 0, curr_str);
    return result;
  }
};