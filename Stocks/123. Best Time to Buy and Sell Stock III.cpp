//
// Created by Suhas Reddy on 3/6/25.
//

/*
 * Idea here is you can assume you can buy second stock at discounted price
 * where discounted price = profit gained in first transaction
 *
 */
//Best solution with O(N) time and O(1) space complexity
class Solution
{
  public:
  int maxProfit(vector<int>& prices)
  {
    int t1Cost = INT_MAX, t2Cost = INT_MAX;
    int t1Profit = 0, t2Profit = 0;

    for (int price : prices)
    {
      // the maximum profit if only one transaction is allowed
      t1Cost = min(t1Cost, price);
      t1Profit = max(t1Profit, price - t1Cost);
      // re-invest the gained profit in the second transaction
      t2Cost = min(t2Cost, price - t1Profit);
      t2Profit = max(t2Profit, price - t2Cost);
    }
    return t2Profit;
  }
};


/*
 * Here you can buy and sell at most two times where you buy1->sell1->buy2->sell2
 * Approach - Find two subsequences that yield the most profit (assuming splitting the array into 2)
 * Search for one subsequence starting left and right each and
 * find the max_profit which could be obtained
 * */

//O(n) time and space complexity
class Solution {
public:
  int maxProfit(vector<int>& prices)
  {
    int size = prices.size();

    if(size<=1)
      return 0;

    vector<int>left_profits(size, 0), right_profits(size+1, 0);

    int left_buy=prices[0], right_sell=prices[size-1];

    for(int i=1;i<prices.size(); i++)
    {
      left_buy = min(left_buy, prices[i]);
      left_profits[i]=max(left_profits[i-1], prices[i]-left_buy);

      int right=size-1-i;
      right_sell=max(right_sell, prices[right]);
      right_profits[right]=max(right_profits[right+1], right_sell-prices[right]);
    }

    int max_profit=0;

    for(int i=0;i<size;i++)
    {
      max_profit=max(max_profit, left_profits[i]+right_profits[i+1]);
    }
    return max_profit;
  }
};
