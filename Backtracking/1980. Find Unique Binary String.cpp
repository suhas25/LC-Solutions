//
// Created by Suhas Reddy on 2/19/25.
//

/*
 * O(n^2) time complexity
 * insert all elements into set.
 * iterate through adding 0/1 to the string.
 * If size matches return the result if its not found in the set.
 *
 * */

class Solution
{
  public:

  unordered_set<string>s;

  string helper(vector<string>& nums, string curr_string)
  {
    if(curr_string.size()==nums.size())
    {
      if(s.find(curr_string)==s.end())
        return curr_string;
      return "";
    }

    auto zero_result = helper(nums, curr_string+"0");

    auto one_result = helper(nums, curr_string+"1");

    if(zero_result.size()>=one_result.size())
      return zero_result;

    return one_result;
  }

  string findDifferentBinaryString(vector<string>& nums)
  {
    for(const auto&num:nums)
      s.insert(num);

    return helper(nums, "");
  }
};