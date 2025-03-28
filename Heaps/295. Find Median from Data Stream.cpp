//
// Created by Suhas Reddy on 2/14/25.
//

class MedianFinder
{
  priority_queue<int> lo;
  priority_queue<int, vector<int>, greater<int>> hi;

public:

  void addNum(int num)
  {
    lo.push(num);

    hi.push(lo.top());
    lo.pop();

    if (lo.size() < hi.size())
    {
      lo.push(hi.top());
      hi.pop();
    }
  }

  double findMedian()
  {
    return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
  }
};

