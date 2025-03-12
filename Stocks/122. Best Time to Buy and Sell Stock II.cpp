//
// Created by Suhas Reddy on 3/6/25.

//O(n) time and O(1) space complexity
//Buy and sell infinity number of times but could hold only max of 1 stock at a time.
class Solution {
public:
  int maxProfit(vector<int>& prices)
  {
    int profit=0;

    for(int i=1;i<prices.size(); i++)
    {
      if(prices[i]>prices[i-1])
        profit+=prices[i]-prices[i-1];
    }
    return profit;
  }
};

//Peak and valley approach
class Solution
{
  public:
    int maxProfit(vector<int>& prices)
    {
      int i = 0;
      int valley = prices[0];
      int peak = prices[0];
      int maxprofit = 0;

      //peak should always follow a valley (buy at valley and sell at peak)
      while (i < prices.size() - 1)
      {
        //find valley
        while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;
        valley = prices[i];

        //find peak
        while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;
        peak = prices[i];
        maxprofit += peak - valley;
      }
      return maxprofit;
  }
};
