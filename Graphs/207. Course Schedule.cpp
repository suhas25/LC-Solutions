//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
  {
    unordered_map<int, vector<int>>adjList;

    vector<int>indegree(numCourses, 0);

    for(auto prereq:prerequisites)
    {
      adjList[prereq[1]].push_back(prereq[0]);
      indegree[prereq[0]]++;
    }

    queue<int>q;
    for(int i=0;i<indegree.size(); i++)
    {
      if(indegree[i]==0)
        q.push(i);
    }

    int nodesVisited = 0;
    while(!q.empty())
    {
      auto ele = q.front();
      nodesVisited++;
      q.pop();

      for(auto node:adjList[ele])
      {
        if(--indegree[node]==0)
          q.push(node);
      }
    }

    return nodesVisited==numCourses;
  }
};
