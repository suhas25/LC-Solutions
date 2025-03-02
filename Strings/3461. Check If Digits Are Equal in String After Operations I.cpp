//
// Created by Suhas Reddy on 3/2/25.
//

class Solution
{
  public:
  bool hasSameDigits(string s)
  {
    for(int j=0;j<s.size()-2; j++)
    {
      for(int i=0;i<s.size()-1; i++)
        s[i] = (s[i]-'0' + s[i+1]-'0')%10+'0';
    }
    return s[0]==s[1];
  }
};