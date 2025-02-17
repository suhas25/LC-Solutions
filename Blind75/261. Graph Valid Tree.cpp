//
// Created by Suhas Reddy on 2/14/25.
//

class Solution
{
  public:

    unordered_set<int> visited;
    bool is_valid_helper(int curr_node, int parent_node, vector<vector<int>>& adj)
    {
      if (visited.count(curr_node))
        return false;

      visited.insert(curr_node);

      for (auto nei : adj[curr_node])
      {
        if (nei == parent_node)
          continue;

        if(!is_valid_helper(nei, curr_node, adj))
          return false;
      }

      return true;
    }

    bool validTree(int n, vector<vector<int>>& edges)
    {
      if (edges.size() != n - 1) return false;

      vector<vector<int>> adj(n);

      for (auto edge : edges)
      {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }

      if(!is_valid_helper(0, -1, adj))
        return false;

      return n == visited.size();
    }
};