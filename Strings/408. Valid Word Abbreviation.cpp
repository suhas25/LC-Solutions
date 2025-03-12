//
// Created by Suhas Reddy on 3/8/25.
//

//O(M) time complexity
class Solution
{
public:
  bool validWordAbbreviation(string word, string abbr)
  {
    int i=0, j=0;

    while(i<word.size() && j<abbr.size())
    {
      char ch = abbr[j];
      if(isdigit(ch))
      {
        if(ch=='0') return false;

        int value=0;

        while(j<abbr.size() && isdigit(abbr[j]))
        {
          value=value*10+abbr[j]-'0';
          j++;
        }
        while(value--)
          i++;
      }
      else if(word[i++]!=abbr[j++])
        return false;
    }
    return i==word.size() && j==abbr.size();
  }
};
