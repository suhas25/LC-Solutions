//
// Created by Suhas Reddy on 3/7/25.
//

class Solution
{
public:
  bool isOneEditDistance(string s, string t)
  {
    int size1=s.size();
    int size2=t.size();

    if(size1>size2)
      return isOneEditDistance(t, s);

    if(size2-size1>1)
      return false;

    /*
    Two possible cases are
    1. size1==size2
    2. size1==size2+1
    */

    //iterate through shorter string
    for(int i=0;i<size2; i++)
    {
      if(s[i]!=t[i])
      {
        if(size1==size2)
          return s.substr(i+1)==t.substr(i+1);
        else
          return s.substr(i)==t.substr(i+1);
      }
    }
    return size1!=size1;
  }
};