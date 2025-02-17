//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  Node* cloneGraph(Node* node)
  {
    if(node==nullptr)
      return node;

    unordered_map<Node*, Node*>nodes_mapping;

    queue<Node*>q;
    q.push(node);

    while(!q.empty())
    {
      auto curr_node = q.front();
      q.pop();

      if(nodes_mapping.find(curr_node)==nodes_mapping.end())
      {
        Node* newnode = new Node(curr_node->val);
        nodes_mapping.insert({curr_node, newnode});
      }

      for(auto nei:curr_node->neighbors)
      {
        if(nodes_mapping.find(nei)==nodes_mapping.end())
        {
          Node* newnode = new Node(nei->val);
          nodes_mapping.insert({nei, newnode});
          q.push(nei);
        }

        nodes_mapping[curr_node]->neighbors.push_back(nodes_mapping[nei]);
      }
    }
    return nodes_mapping[node];
  }
};