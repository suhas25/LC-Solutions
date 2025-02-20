//
// Created by Suhas Reddy on 2/17/25.
//

class Solution
{
public:
  vector<int> findBottomView(Node* root)
  {
    vector<int> ans;
    if(root == nullptr)
      return ans;

    //vertical column ->val
    map<int,int>mp;
    queue<pair<Node*, int>>Q; // node, column values
    Q.push({root, 0});

    while(!Q.empty())
    {
      auto it = Q.front();
      Q.pop();
      Node* node = it.first;
      int col = it.second;
      mp[col] = node->data;

      if(node->left != NULL)
        Q.push({node->left, col-1});
      if(node->right != NULL)
        Q.push({node->right, col+1});
    }

    for(auto x:mp){
      ans.push_back(x.second);
    }
    return ans;
  }
};


