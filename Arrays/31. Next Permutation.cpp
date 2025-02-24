//
// Created by Suhas Reddy on 2/23/25.
//

/*
 *
 * 1. we traverse from right to left and using two pointers a[i-1] and a[i].
 * 2. we stop at index i-1 where a[i-1]<a[i] (i.e when array values increase here)
 * 3. we need to find an element to the right of a[i-1] (which is in decreasing order) which is just greater than a[i-1] and swap both
 * 4. once we swap, we reverse the elements starting index a[i] to end of array.
 * - when array is already decreasing order, we won't come across index a[i-1] where a[i-1]<a[i].
 * - in that case, we directly reverse all the elements of array.
 *
 * */

//O(n) time complexity and O(1) space complexity

class Solution {
public:
  void nextPermutation(vector<int>& nums)
  {
    int index_to_swap=-1;
    for(int i=nums.size()-1; i>0; i--)
    {
      if(nums[i-1]<nums[i])
      {
        index_to_swap=i-1;
        break;
      }
    }

    //index to swap is set to -1 when the array is in decreasing order.
    if(index_to_swap!=-1)
    {
      for(int i=nums.size()-1;i>index_to_swap; i--)
      {
        if(nums[index_to_swap]<nums[i])
        {
          swap(nums[i], nums[index_to_swap]);
          break;
        }
      }
    }

    reverse(nums.begin()+ index_to_swap+1, nums.end());
  }
};
