//
// Created by Suhas Reddy on 2/17/25.
//


class BSTIterator {
public:
  std::vector<int>v;
  int index;

  void inorder(TreeNode* root)
  {
    if(root==nullptr)
      return;

    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
  }

  BSTIterator(TreeNode* root)
  {
    inorder(root);
    index = -1;
  }

  int next()
  {
    return v[++index];

  }

  bool hasNext() {
    return index+1<v.size();
  }
};