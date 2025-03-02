//
// Created by Suhas Reddy on 3/2/25.
//

/*
/ Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

Node() {}

Node(int _val) {
  val = _val;
}

Node(int _val, vector<Node*> _children) {
  val = _val;
  children = _children;
}
};
*/

class Solution {
public:
  Node* cloneTree(Node* root)
  {
    if (root == nullptr)
      return nullptr;

    Node* new_root = new Node(root->val);

    for (auto child: root->children)
      new_root->children.push_back(cloneTree(child));

    return new_root;
  }
};