//
// Created by Suhas Reddy on 3/6/25.
//

//Obtain the max profit where you could buy/sell at max once
//O(n) time and O(1) space complexity
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
