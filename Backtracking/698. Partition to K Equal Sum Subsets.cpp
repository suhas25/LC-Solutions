//
// Created by Suhas Reddy on 2/19/25.
//

//Resulted in TLE. Possibly need to use memoization.
//possibly use unordered_map<string, bool> where each index in string refers to val at that index is picked or not
//and that if combination resulted in valid partition.
class Solution
{
  int size;
public:
  bool helper(vector<int>& nums, int target_sum, int curr_sum, int index, int k, vector<bool>&visited)
  {
    //base case - we can make kth partition when we are able to make k-1 equal partitions already
    if(k==1)
      return true;

    if(curr_sum>target_sum)
      return false;

    if(index>=size)
      return false;

    //we made one successful partition, lets make others now.
    //notice we are updating index to zero here. we again start picking unpicked elements for next partition from starting index which are not picked up.
    if(curr_sum==target_sum)
    {
      return helper(nums, target_sum, 0, 0, k-1, visited);
    }

    for(int i=index;i<size; i++)
    {
      //index already picked up.
      if(!visited[i])
      {
        visited[i]=true;

        if(helper(nums, target_sum, curr_sum+nums[i], i+1, k, visited))
          return true;

        visited[i]=false;
      }
    }
    return false;
  }

  bool canPartitionKSubsets(vector<int>& nums, int k)
  {
    int total_sum=0;
    size = nums.size();

    for(auto num:nums)
      total_sum+=num;

    if(total_sum%k!=0)
      return false;

    sort(nums.begin(), nums.end(), greater<int>());

    vector<bool>visited(nums.size(), false);

    int target_sum = total_sum/k;

    return helper(nums, target_sum, 0, 0, k, visited);
  }
};