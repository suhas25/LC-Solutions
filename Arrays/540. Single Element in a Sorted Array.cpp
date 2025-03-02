//
// Created by Suhas Reddy on 3/2/25.
//

/*
 * logic here is to apply binary search with idea that at index (0,1) element
 * should be same and at index (2, 3) it should be next element and so on.
 *
 * i.e if index is even, then index and index+1 should have same val,
 * if index is odd, index-1 and index should have same val.
 * But on this, we split the array
 * */


//O(n) time and O(1) space complexity
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {

    int low = 0;
    int high = nums.size()-1;

    while (low <=high)
    {
      int mid = low + (high - low) / 2;

      if (mid % 2 == 0)
      {
        if (mid + 1 < nums.size() && nums[mid + 1] == nums[mid])
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
      else
      {
        if (mid - 1 >= 0 && nums[mid - 1] == nums[mid])
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
    }

    return nums[low];
  }
};
