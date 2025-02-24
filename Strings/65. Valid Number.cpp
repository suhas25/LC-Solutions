//
// Created by Suhas Reddy on 2/20/25.
//

/*
rules
+/- should be followed by (e or E) if its not seen in first index
e/E can be only once and has to be followed by digit
. can come only once and exponent (e or E) has to follow dot. cannot come before dot.
exponent (e/E) has to be fllowed by a digit.
*/

class Solution {
public:
  bool isNumber(string s)
  {
    bool seendot=false, seendigit=false, seenexponent=false;

    for(int i=0;i<s.size(); i++)
    {
      auto curr = s[i];

      if(curr>='0' && curr<='9')
        seendigit=true;
      else if(curr=='+' || curr=='-')
      {
        if(i>0 && s[i-1]!='e' && s[i-1]!='E')
          return false;
      }
      else if(curr=='e' || curr=='E')
      {
        if(seenexponent || !seendigit)
          return false;
        seenexponent=true;
        seendigit=false;
      }
      else if(curr=='.')
      {
        if(seendot || seenexponent)
          return false;
        seendot=true;
      }
      else
        return false;
    }
    return seendigit;
  }
};