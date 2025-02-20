//
// Created by Suhas Reddy on 2/19/25.
//

//Use inorder traversal over two trees and compare the top node on stack.
class Solution {
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
  {
    stack<TreeNode*> stk1, stk2;
    vector<int>result;

    while(root1!=nullptr || !stk1.empty() || root2!=nullptr || !stk2.empty())
    {
      while(root1)
      {
        stk1.push(root1);
        root1=root1->left;
      }

      while(root2)
      {
        stk2.push(root2);
        root2=root2->left;
      }

      if(stk1.empty() || (!stk2.empty() && stk1.top()->val>stk2.top()->val))
      {
        root2=stk2.top();
        result.push_back(root2->val);
        stk2.pop();
        root2=root2->right;
      }
      else
      {
        root1=stk1.top();
        result.push_back(root1->val);
        stk1.pop();
        root1=root1->right;
      }
    }
    return result;
  }
};
