//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int hammingWeight(uint32_t n)
  {
    int count = 0;
    while(n)
    {
      n=n&(n-1);
      count++;
    }
    return count;
  }
};

class Solution2 {
public:
  int hammingWeight(uint32_t n)
  {
    int count=0;
    for(int i=0;i<32; i++)
    {
      if(1<<i && n)
        count++;
    }
    return count;
  }
};

class Solution3 {
public:
  int hammingWeight(uint32_t n)
  {
    int count=0;

    while(n!=0)
    {
      count+=(n&1)?1:0;
      n=n>>1;
    }
    return count;
  }
};