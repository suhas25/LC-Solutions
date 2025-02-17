//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int findMin(vector<int>& nums)
  {
    int left =0, right = nums.size()-1;

    while(left<right)
    {
      int mid = left+(right-left)/2;

      //right half is sorted. search in left half
      if(nums[mid]<nums[right])
        right = mid;
      else
        left = mid+1; //search in unsorted right half
    }
    return nums[left];
  }
};

class Solution2 {
public:
  int findMin(vector<int>& nums) {
    int result = nums[0];

    int size = nums.size();
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
      // array is sorted
      if (nums[low] < nums[high])
        return nums[low];

      int mid = low + (high - low) / 2;

      if ((mid == 0 || nums[mid - 1] > nums[mid]) &&
          (mid == size - 1 || nums[mid] < nums[mid + 1]))
        return nums[mid];

      // search in unsorted right half
      else if (nums[low] <= nums[mid])
        low = mid + 1;
      else
        high = mid - 1; // search in unsorted left half
    }

    return result;
  }
};

class Solution3
{
public:
  int findMin(vector<int>& nums)
  {
    int result = nums[0];

    int left =0, right = nums.size()-1;

    while(left<=right)
    {
      if(nums[left<nums[right]])
        result = min(result, nums[left]);

      int mid = left + (right-left)/2;

      if(nums[left]<=nums[mid])
      {
        result = min(result, nums[left]);
        left = mid+1;
      }
      else
      {
        result = min(result, nums[right]);
        right = mid-1;
      }
    }

    return result;
  }
};