//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int search(vector<int>& nums, int target)
  {
    int low = 0;
    int high = nums.size()-1;

    while(low<=high)
    {
      int mid = low + (high-low)/2;

      if(nums[mid]==target)
        return mid;

      //left half sorted
      else if(nums[low]<=nums[mid])
      {
        if(nums[low]<=target && target<nums[mid])
          high = mid-1;
        else
          low = mid+1; //search in unsorted right half
      }
      //right half sorted
      else
      {
        if(nums[mid]<target && target<=nums[high])
          low = mid+1;
        else
          high = mid-1; //search in unsorted left half
      }
    }
    return -1;
  }
};
