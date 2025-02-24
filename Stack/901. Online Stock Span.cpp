//
// Created by Suhas Reddy on 2/21/25.
//

//The span of the stock's price in one day is the maximum number of consecutive days
// (starting from that day and going backward) for
//which the stock price was less than or equal to the price of that day.

class StockSpanner {
public:
  //price -> span;
  stack<pair<int, int>>stk;

  StockSpanner() {
        
  }
    
  int next(int price)
  {
    int span = 1;
    while(!stk.empty() && stk.top().first<=price)
    {
      span+=stk.top().second;
      stk.pop();
    }

    stk.push({price, span});
    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */