//
// Created by Suhas Reddy on 2/19/25.
//

class Solution { // 20 ms, faster than 86.78%
public:
  vector<vector<int>> levelOrder(Node* root)
  {
    if (root == nullptr)
      return {};

    queue<Node*> q;
    q.push(root);

    vector<vector<int>> res;

    while (!q.empty())
    {
      vector<int> level;
      int size = q.size();

      for (int i=0;i<size; i++)
      {
        auto curr = q.front();
        level.push_back(curr->val);
        q.pop();

        for(auto node:curr->children)
          q.push(node);
      }
      res.push_back(level);
    }
    return res;
  }
};