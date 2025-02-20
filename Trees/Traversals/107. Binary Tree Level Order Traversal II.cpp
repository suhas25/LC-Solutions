//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root)
  {
    vector<vector<int>> result;
    queue<TreeNode*>q;
    if(root==NULL)
      return {};

    q.push(root);

    while(!q.empty())
    {
      int size = q.size();
      vector<int>temp;
      for(int i=0;i<size; i++)
      {
        TreeNode* curr_node = q.front();
        q.pop();
        temp.push_back(curr_node->val);
        if(curr_node->left !=NULL)
          q.push(curr_node->left);
        if(curr_node->right !=NULL)
          q.push(curr_node->right);
      }
      result.push_back(temp);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
