//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
  {
    if(preorder.empty() || inorder.empty())
      return nullptr;

    TreeNode* root = new TreeNode(preorder[0]);

    auto mid_index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

    vector<int> leftIn(inorder.begin(), inorder.begin() + mid_index);
    vector<int> rightIn(inorder.begin() + mid_index + 1, inorder.end());

    vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid_index + 1);
    vector<int> rightPre(preorder.begin() + mid_index + 1, preorder.end());

    
    root->left = buildTree(leftPre, leftIn);
    root->right = buildTree(rightPre, rightIn);

    return root;
  }
};




