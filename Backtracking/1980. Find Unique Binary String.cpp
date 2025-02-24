//
// Created by Suhas Reddy on 2/19/25.
//

// Cantor's Diagonal Argument
//O(n) time complexity
class Solution
{
  public:
    string findDifferentBinaryString(vector<string>& nums)
    {
      string ans;
      for (int i = 0; i < nums.size(); i++)
      {
        char curr = nums[i][i];
        ans += curr == '0' ? '1' : '0';
      }
      return ans;
    }
};

/*
 *
 * O(n^2) time complexity
 * insert all elements into set.
 * iterate through adding 0/1 to the string.
 * If size matches return the result if its not found in the set.
 *
 * */

class Solution2
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