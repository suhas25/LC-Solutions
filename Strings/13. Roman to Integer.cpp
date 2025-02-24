//
// Created by Suhas Reddy on 2/20/25.
//

class Solution {
public:
  unordered_map<string, int>mapping{{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40},{"XC", 90}, {"CD", 400}, {"CM", 900}};
  int romanToInt(string s)
  {
    int result=0;
    int i=0;
    while(i<s.size())
    {
      if(i+1<s.size())
      {
        auto digit = s.substr(i, 2);
        if(mapping.count(digit))
        {
          result+=mapping[digit];
          i+=2;
          continue;
        }
      }

      string digit = s.substr(i, 1);
      result+=mapping[digit];

      i++;
    }
    return result;
  }
};
