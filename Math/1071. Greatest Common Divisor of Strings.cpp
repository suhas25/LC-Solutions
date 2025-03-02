//
// Created by Suhas Reddy on 3/2/25.
//

//O(m+n) time complexity
class Solution
{
public:
  string gcdOfStrings(string str1, string str2)
  {
    if(str1+str2!=str2+str1)
      return "";

    int gcd_length= gcd(str1.size(), str2.size());

    return str1.substr(0, gcd_length);
  }
};

//O(log(min(a, b)))
int gcd(int a, int b)
{
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// a*b = LCM(a,b) * GCD(a, b)
int lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;  // Prevents overflow
}