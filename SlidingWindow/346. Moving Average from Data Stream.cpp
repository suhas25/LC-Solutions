//
// Created by Suhas Reddy on 3/2/25.
//

class MovingAverage {
public:
  queue<int> q;
  int window_sum = 0;
  int size;
  MovingAverage(int size)
  {
    this->size=size;
  }

  double next(int val)
  {
    window_sum += val;
    q.push(val);

    if (q.size()> size)
    {
      window_sum -= q.front();
      q.pop();
    }
    return( window_sum * 1.0 )/ q.size();
  }
};
