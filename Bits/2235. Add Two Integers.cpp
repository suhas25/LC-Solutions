//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  int sum(int num1, int num2)
  {
    while(num2)
    {
      int carry = (num1&num2)<<1;
      num1 = num1^num2;
      num2=carry;
    }

    return num1;
  }
};