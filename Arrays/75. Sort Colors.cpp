//
// Created by Suhas Reddy on 2/23/25.
//

/*
 * Dutch National flag problem
 * array to left of index p0 has all zeroes.
 * array to right of index p2 has all 2's
 * array between p1 and p2 is unsorted half.
 * */

class Solution
{
  public:
  void sortColors(vector<int>& nums)
  {
    int p0=0, p1=0, p2=nums.size()-1;

    while(p1<=p2)
    {
      if(nums[p1]==0)
      {
        swap(nums[p0], nums[p1]);
        p0++, p1++;
      }
      else if(nums[p1]==2)
      {
        swap(nums[p2], nums[p1]);
        p2--;
      }
      else
        p1++;
    }
    return;
  }
};
