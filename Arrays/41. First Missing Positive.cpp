//
// Created by Suhas Reddy on 2/23/25.
//
/*
 * Cyclic Sort
 * Cycle sort is a sorting algorithm that can sort a given sequence in a range
 * from a to n by putting each element at the index that corresponds to its value.
 * iterate through array and place elements falling within window (1, n) at correct index(0, n-1).
 * now iterate and return the element not found.
 * */

class Solution
{
public:
  int firstMissingPositive(vector<int>& nums)
  {
    int n = nums.size();

    int i=0;
    while(i<n)
    {
      //int correct_index=nums[i]-1;
      if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
      {
        swap(nums[i], nums[nums[i]-1]);
      }
      else
        i++;
    }

    for(int i=0;i<nums.size(); i++)
    {
      if(nums[i]!=i+1)
        return i+1;
    }

    return n+1;
  }
};
