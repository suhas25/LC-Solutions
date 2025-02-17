//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  void dfs(vector<int> adjList[], vector<int> &visited, int src) {
    visited[src] = 1;

    for (auto ele:adjList[src]) {
      if (visited[ele] == 0) {
        dfs(adjList, visited, ele);
      }
    }
  }

  int countComponents(int n, vector<vector<int>>& edges) {

    if (n == 0) return 0;

    int components = 0;
    vector<int> visited(n, 0);
    vector<int> adjList[n];

    for (int i = 0; i < edges.size(); i++) {
      adjList[edges[i][0]].push_back(edges[i][1]);
      adjList[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
      if (visited[i] == 0)
      {
        components++;
        dfs(adjList, visited, i);
      }
    }
    return components;
  }
};

