//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int maxProfit(vector<int>& prices)
  {
    int min_price=prices[0];
    int max_profit=0;

    for(auto price:prices)
    {
      min_price = min(price, min_price);
      max_profit = max(max_profit, price-min_price);
    }

    return max_profit;

  }
};

//Using Sliding Window
class Solution2 {
public:
  int maxProfit(vector<int>& prices)
  {
    int left=0, right = 1;
    int max_profit = 0;

    while(right<prices.size())
    {
      if(prices[left]<prices[right])
      {
        max_profit = max(max_profit, prices[right]-prices[left]);
      }
      else{
        left = right;
      }
      right++;
    }

    return max_profit;
  }
};