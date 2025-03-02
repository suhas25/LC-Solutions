//
// Created by Suhas Reddy on 2/25/25.
//

class Solution
{
  public:
  //calculating square of each digit and summing up to get next number
  int get_next_number(int n)
  {
    int result=0;
    while(n>0)
    {
      int digit=n%10;
      n=n/10;
      result+=digit*digit;
    }
    return result;
  }

  //This approach was based on the idea that all numbers either end at 1 or enter the cycle {4, 16, 37, 58, 89, 145, 42, 20}
  bool isHappy(int n)
  {
    while(n!=1 && n!=4)
      n=get_next_number(n);

    return n==1;
  }
};

class Solution2
{
  public:
  int getNext(int n)
    {
    int totalSum = 0;
    while (n > 0)
    {
      int d = n % 10;
      n = n / 10;
      totalSum += d * d;
    }
    return totalSum;
  }

  bool isHappy(int n)
  {
    int slowRunner = n;
    int fastRunner = getNext(n);
    while (fastRunner != 1 && slowRunner != fastRunner)
    {
      slowRunner = getNext(slowRunner);
      fastRunner = getNext(getNext(fastRunner));
    }
    return fastRunner == 1;
  }
};
