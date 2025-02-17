//
// Created by Suhas Reddy on 2/16/25.
//

/*
 *
 * Boyer-Moore voting algo.
 * only max of 1 majority element1 can appear more than floor(n/2) times.
 * only max of 2 majority elements can appear more than floor(n/3) times.
 * only max of 3 majority elements can appear more than floor(n/4) times.
 * */

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums)
  {
    int count1=0, count2=0;
    int candidate1=INT_MAX, candidate2=INT_MAX;

    for(auto num:nums)
    {
      if(candidate1!=INT_MAX && candidate1==num)
        count1++;
      else if(candidate2!=INT_MAX && candidate2==num)
        count2++;
      else if(count1==0)
      {
        candidate1=num;
        count1++;
      }
      else if(count2==0)
      {
        candidate2=num;
        count2++;
      }
      else
      {
        count1--;
        count2--;
      }
    }

    //now validate if they appear more than ceil(n/3) times

    vector<int>result;

    count1=0, count2=0;
    for(auto num:nums)
    {
      if(candidate1!=INT_MAX && num==candidate1)
        count1++;
      if(candidate2!=INT_MAX && num==candidate2)
        count2++;
    }

    if(count1>nums.size()/3)
      result.push_back(candidate1);

    // avoid duplicates
    if(candidate1==candidate2)
      return result;

    if(count2>nums.size()/3)
      result.push_back(candidate2);

    return result;
  }
};