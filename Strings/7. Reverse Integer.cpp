//
// Created by Suhas Reddy on 2/20/25.
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

//declare result at long and validate INT_MAX/INT_MIN at end.
class Solution2
{
public:
  int reverse(int x)
  {
    long result=0;
    while(x)
    {
      result=result*10+x%10;
      x=x/10;
    }

    if(result>INT_MAX || result<INT_MIN)
      return 0;

    return static_cast<int>(result);
  }
};
