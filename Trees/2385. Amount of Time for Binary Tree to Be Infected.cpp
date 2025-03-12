//
// Created by Suhas Reddy on 3/5/25.
//

/*
 * Build an adjaceny list (graph) and do a BFS starting the infected node
 * Below Solution works given binary tree has unique values. Otherwise,
 * will have to maintain a map and set of TreeNode* and keep track of the starting infectious node while
 * building graph.
 */

//O(n) time and space complexity
class Solution
{
  unordered_set<int>visited;
  unordered_map<int, unordered_set<int>> adjList;
public:
  int amountOfTime(TreeNode* root, int start)
  {
    build_graph(root);

    queue<int>q;
    q.push(start);
    int time =0;
    visited.insert(start);

    while(!q.empty())
    {
      int sizee=q.size();
      for(int i=0;i<sizee; i++)
      {
        auto curr = q.front();
        q.pop();

        for(auto num:adjList[curr])
        {
          if(!visited.count(num))
          {
            visited.insert(num);
            q.push(num);
          }
        }
      }
      time++;
    }
    return time-1;
  }

  void build_graph(TreeNode* node)
  {
    if(node==nullptr)
      return;

    if(node->left!=nullptr)
    {
      adjList[node->left->val].insert(node->val);
      adjList[node->val].insert(node->left->val);
    }

    if(node->right!=nullptr)
    {
      adjList[node->right->val].insert(node->val);
      adjList[node->val].insert(node->right->val);
    }

    build_graph(node->left);
    build_graph(node->right);
  }
};
