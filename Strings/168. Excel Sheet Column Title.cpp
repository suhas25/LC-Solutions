//
// Created by Suhas Reddy on 3/2/25.
//

class Solution
{
  public:
  string convertToTitle(int columnNumber)
  {
    string result;
    while(columnNumber)
    {
      columnNumber--;
      result+=(char)((columnNumber)%26+'A');
      columnNumber/=26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};