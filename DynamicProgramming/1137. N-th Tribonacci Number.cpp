//
// Created by Suhas Reddy on 2/26/25.
//

class Solution
{
  public:
  int tribonacci(int n) // we need to calculate n+1 out of which we have zeroth, 1st and 2nd.
  {
    if (n < 3)
    {
      return n > 0 ? 1 : 0;
    }

    int a = 0, b = 1, c = 1;

    for (int i = 0; i < n - 2; ++i)
    {
      int tmp = a + b + c;
      a = b;
      b = c;
      c = tmp;
    }
    return c;
  }
};
