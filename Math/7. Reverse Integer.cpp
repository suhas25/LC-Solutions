//
// Created by Suhas Reddy on 2/24/25.
//

class Solution {
public:
  int reverse(int x)
  {
    int result=0;
    while(x)
    {
      //INT_MIN -> –2147483648 INT_MAX -> 2147483647
      auto digit = x%10;
      if((result>INT_MAX/10) || ((result==INT_MAX/10) && digit>7))
        return 0;

      if((result<INT_MIN/10) || ((result==INT_MIN/10) && digit<-8))
        return 0;

      result =result*10+digit;
      x=x/10;
    }
    return result;
  }
};