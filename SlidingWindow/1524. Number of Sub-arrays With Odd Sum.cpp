//
// Created by Suhas Reddy on 2/25/25.
//

//O(n) time and O(1) space complexity.
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


//O(n^2) TLE Solution
class Solution2 {
public:
  int numOfSubarrays(vector<int>& arr)
  {
    int count = 0;

    for(int i=0;i< arr.size(); i++)
    {
      int sum=0;
      for(int j=i;j<arr.size(); j++)
      {
        sum+=arr[j];

        if(sum%2==1)
          count++;
      }
    }
    return count;
  }
};
