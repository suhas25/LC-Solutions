//
// Created by Suhas Reddy on 2/17/25.
//

class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {

    unsigned int max_width=0;
    if(!root)
      return 0;

    deque<pair<TreeNode*, unsigned int>> q;

    q.push_back({root, 1});

    while(!q.empty())
    {
      int size=q.size();
      max_width = max(max_width, q[size-1].second-q[0].second+1);
      for(int i=0;i<size; i++)
      {
        auto [node, index]=q.front();
        q.pop_front();

        if(node->left)
          q.push_back({node->left, 2*index});
        if(node->right)
          q.push_back({node->right, 2*index+1});
      }

    }
    return max_width;
  }
};
