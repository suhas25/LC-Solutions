//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    vector<int>LSum(nums.size(), 1);
    vector<int>RSum(nums.size(), 1);
    vector<int>answer(nums.size());

    for(int i=1;i<nums.size(); i++)
    {
      LSum[i]=LSum[i-1]*nums[i-1];
    }

    for(int i=nums.size()-2;i>=0;i--)
    {
      RSum[i]=RSum[i+1]*nums[i+1];
    }

    for(int i=0;i<nums.size(); i++)
    {
      answer[i]=LSum[i]*RSum[i];
    }


    return answer;
  }
};

//optimal solution
class Solution2 {
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    vector<int>answer(nums.size());

    int prefix_sum=1;

    for(int i=0;i<nums.size(); i++)
    {
      answer[i]=prefix_sum;
      prefix_sum=prefix_sum*nums[i];
    }

    int suffix_sum=1;
    for(int i=nums.size()-1;i>=0;i--)
    {
      answer[i]=suffix_sum;
      suffix_sum=suffix_sum*nums[i];
    }

    return answer;
  }
};
