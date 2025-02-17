//
// Created by Suhas Reddy on 2/14/25.
//
class Solution {
public:
  vector<int> countBits(int n)
  {
    if(n==0 || n==1)
      return n;

    vector<int>res(n+1,0);
    res[0]=0;
    res[1]=1;

    for(int i=2;i<=n; i++)
      if(i%2==1)
        res[i]=res[i/2]+1;
      else
        res[i]=res[i/2];

    return res;

  }
};