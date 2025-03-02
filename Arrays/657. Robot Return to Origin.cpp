//
// Created by Suhas Reddy on 3/2/25.
//

class Solution
{
  public:
  bool judgeCircle(string moves)
  {
    int x=0, y=0;
    for(auto move:moves)
    {
      if(move=='U')
        y++;
      if(move=='D')
        y--;
      if(move=='L')
        x--;
      if(move=='R')
        x++;
    }

    return x==0 && y==0;
  }
};
