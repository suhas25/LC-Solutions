//
// Created by Suhas Reddy on 2/21/25.
//

/*
- Can be done in 2 approaches.
1. Using parent pointers
2. Building graph using DFS.
*/

//O(n) time and space complexity
class Solution
{
public:
  unordered_map<TreeNode*, TreeNode*> child_to_parent_mapping;
  unordered_set<TreeNode*> visited;
  vector<int>result;

  void helper(TreeNode* child, TreeNode* parent)
  {
    if(child==nullptr)
      return;

    child_to_parent_mapping.insert({child, parent});

    helper(child->left, child);
    helper(child->right, child);
  }

  void DFS(TreeNode* node, int distance)
  {
    if(node==nullptr || visited.count(node))
      return;

    visited.insert(node);

    if(distance==0)
    {
      result.push_back(node->val);
      return;
    }

    DFS(node->left, distance-1);
    DFS(node->right, distance-1);
    DFS(child_to_parent_mapping[node], distance-1);
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
  {
    helper(root, nullptr);

    DFS(target, k);

    return result;
  }
};

//build graph and do DFS. BFS also works
class Solution2 {
public:
  unordered_map<int, vector<int>> graph;
  vector<int> result;
  unordered_set<int> visited;

  vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
  {
    buildGraph(root, nullptr);

    visited.insert(target->val);
    dfs(target->val, 0, K);

    return result;
  }

  // Recursively build the undirected graph from the given binary tree.
  void buildGraph(TreeNode* current, TreeNode* parent)
  {
    if (current != nullptr && parent != nullptr)
    {
      graph[current->val].push_back(parent->val);
      graph[parent->val].push_back(current->val);
    }
    if (current->left != nullptr)
      buildGraph(current->left, current);

    if (current->right != nullptr)
      buildGraph(current->right, current);
  }

  void dfs(int current, int distance, int K)
  {
    if (distance == K) {
      result.push_back(current);
      return;
    }

    for (int neighbor : graph[current])
    {
      if (visited.find(neighbor) == visited.end())
      {
        visited.insert(neighbor);
        dfs(neighbor, distance + 1, K);
      }
    }
  }
};
