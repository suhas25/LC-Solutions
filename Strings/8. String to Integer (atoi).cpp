//
// Created by Suhas Reddy on 2/20/25.
//

//O(n) time complexity and O(1) space complexity.

class Solution {
public:
  int myAtoi(string s)
  {
    int len = s.size();
    int result = 0;
    int sign = 1;
    int index = 0;

    //skip white spaces
    while(index<len && s[index]==' ')
    {
      index++;
    }

    //extract sign
    if(index<len && s[index]=='+' || s[index]=='-')
    {
      sign = (s[index]=='+')?1:-1;
      index++;
    }

    while(index<len && isdigit(s[index]))
    {
      int temp_val = s[index]-'0';
      if((result>INT_MAX/10) || (result==INT_MAX/10 && temp_val>INT_MAX%10))
        return sign==1 ?INT_MAX:INT_MIN;

      result= result*10+temp_val;
      index++;
    }
    return sign*result;
  }
};