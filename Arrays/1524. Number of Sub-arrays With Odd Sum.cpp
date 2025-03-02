//
// Created by Suhas Reddy on 3/2/25.
//

/*
 * Set even_count to 1 because of zero length array of value zero.
 * based on logic odd+even ->odd
 * even+odd ->odd
 */

//O(n) time and O(1) space complexity
class Solution {
public:
  int numOfSubarrays(vector<int>& arr)
  {
    int mod = 1e9+7;
    int count=0,odd_count=0, even_count=1, prefix_sum=0;

    for(auto num:arr)
    {
      prefix_sum+=num;

      if(prefix_sum%2==0)
      {
        count+=odd_count;
        even_count++;
      }
      else
      {
        count+=even_count;
        odd_count++;
      }
      count=count%mod;
    }
    return count;
  }
};
