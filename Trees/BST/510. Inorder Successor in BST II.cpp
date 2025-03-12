//
// Created by Suhas Reddy on 3/5/25.
//

//O(h) time complexity
class Solution {
public:
  Node* inorderSuccessor(Node* node)
  {
    if(node->right)
    {
      node=node->right;
      while(node->left!=nullptr)
        node = node->left;
      return node;
    }

    while(node->parent!=nullptr && node==node->parent->right)
      node = node->parent;

    return node->parent;
  }
};
