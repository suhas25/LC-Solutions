//
// Created by Suhas Reddy on 2/15/25.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  TreeNode* invertTree(TreeNode* root)
  {
    if(root == nullptr)
      return root;

    TreeNode* right = invertTree(root->right);
    TreeNode* left = invertTree(root->left);

    root->left = right;
    root->right = left;

    return root;
  }
};

class Solution2 {
public:
  TreeNode* invertTree(TreeNode* root)
  {
    if (!root)
      return nullptr;

    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty())
    {
      TreeNode* node = queue.front();
      queue.pop();

      swap(node->left, node->right);
      if (node->left) queue.push(node->left);
      if (node->right) queue.push(node->right);
    }

    return root;
  }
};
