//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t result = 0;
    uint32_t power = 31;

    while(n!=0)
    {
      result+=(n&1)<<power;//figure out the bit at the ith position using n& 1 and move it to the 31-ith position ( 0-31 bits) using leftshift by the power no of digits.
      power-=1;
      n=n>>1; // shift number to the right i.e divide by 2.
    }

    return result;
  }
};

class Solution2 {
public:
  uint32_t reverseBits(uint32_t n)
  {
    int reverse=0;

    for(int i=0;i<32;i++)
    {
      auto bit = (n>>i) &1;
      reverse=reverse| bit<<(31-i);
    }

    return reverse;

  }
};
