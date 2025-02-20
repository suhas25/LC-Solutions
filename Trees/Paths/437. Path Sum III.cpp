//
// Created by Suhas Reddy on 2/17/25.
//

//Use prefix sum technique
// O(n) time and space comoplexity.

class Solution
{
public:
  unordered_map<long long int, int> map;
  int count = 0;

  void preorder(TreeNode* root, long long int currsum, int target)
  {
    if (root == nullptr)
      return;

    currsum += root->val;

    if (currsum == target)
      count++;

    if (map.find(currsum - target) != map.end())
      count += map[currsum - target];

    map[currsum]++;

    preorder(root->left, currsum, target);
    preorder(root->right, currsum, target);

    map[currsum]--;
  }

  int pathSum(TreeNode* root, int targetSum)
  {
    preorder(root, 0, targetSum);
    return count;
  }
};
