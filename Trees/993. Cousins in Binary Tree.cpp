//
// Created by Suhas Reddy on 2/19/25.
//

// Keep track of Parent and depth/level.
class Solution {
public:

  pair<int, TreeNode*> x_, y_;
  void dfs(TreeNode* root, int x, int y, int depth, TreeNode*parent)
  {
    if(root==nullptr)
      return;

    if(root->val==x)
      x_={depth, parent};
    if(root->val==y)
      y_={depth, parent};

    dfs(root->left, x, y, depth+1, root);
    dfs(root->right, x, y, depth+1, root);

  }

  bool isCousins(TreeNode* root, int x, int y)
  {
    dfs(root, x, y, 0, nullptr);

    return x_.first==y_.first && x_.second!=y_.second;
  }
};
