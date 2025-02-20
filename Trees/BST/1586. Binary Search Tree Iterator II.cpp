//
// Created by Suhas Reddy on 2/18/25.
//

class BSTIterator {
public:
  std::vector<int> v;
  int index;

  void inorder(TreeNode* root)
  {
    if (root == nullptr)
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

  bool hasNext() { return index + 1 < v.size(); }

  int next() { return v[++index]; }

  bool hasPrev() { return index>0;}

  int prev() {return v[--index];}
};

