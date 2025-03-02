//
// Created by Suhas Reddy on 3/2/25.
//

class Solution {
public:
  string clearDigits(string s)
  {
    int res_length=0;

    for(int i=0;i<s.size(); i++)
    {
      if(isdigit(s[i]))
        res_length--;
      else
        s[res_length++]=s[i];
    }

    s.resize(res_length);
    return s;
  }
};

class Solution2
{
public:
  string clearDigits(string s)
  {
    string answer;
    for (int charIndex = 0; charIndex < s.size(); charIndex++)
    {
      if (isdigit(s[charIndex]) && !answer.empty())
        answer.pop_back();
      else
        answer += s[charIndex];
    }
    return answer;
  }
};