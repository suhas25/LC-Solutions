//
// Created by Suhas Reddy on 2/15/25.
//

// Boyer-Moore Voting Algorithm. This works only provided majority number exists in array.

class Solution
{
  public:
    int majorityElement(vector<int>& nums)
    {
      int count = 0;
      int candidate = 0;

      for(auto num:nums)
      {
        if(count==0) // make current num as candidate when num=0;
        {
          candidate = num;
        }

        if(num==candidate)
          count++;
        else
          count--; //probably we choose wrong number as candidate. we need choose another one in next iteration.
      }
      return candidate; //returns non true majority candidate when no majority candidate exists.
    }
};