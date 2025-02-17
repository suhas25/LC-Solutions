//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  int getSum(int a, int b)
  {
    while(b!=0)
    {
      int carry = (a&b)<<1;
      a = a^b;
      b = carry;
    }

    return a;
  }
};
