//
// Created by Suhas Reddy on 2/26/25.
//
//O(n) time and O(logn) space complexity
class Solution {
public:
  TreeNode* helper(vector<int>&nums, int start_index, int end_index)
  {
    if(start_index>end_index)
      return nullptr;
    int mid = start_index+(end_index-start_index)/2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left=helper(nums, start_index, mid-1);
    root->right= helper(nums, mid+1, end_index);

    return root;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums)
  {
    if(nums.empty())
      return nullptr;
    return helper(nums, 0, nums.size()-1);
  }
};
