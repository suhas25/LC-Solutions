//
// Created by Suhas Reddy on 3/2/25.
//

class Solution {
public:
  map<Node*, NodeCopy*> old_to_new;

  NodeCopy* deepcopy(Node* root)
  {
    if(root==nullptr)
      return nullptr;

    auto new_root = new NodeCopy(root->val);
    old_to_new[root]=new_root;

    new_root->left = deepcopy(root->left);
    new_root->right = deepcopy(root->right);

    return old_to_new[root];
  }

  void copy_random(Node* root)
  {
    if(root==nullptr)
      return ;

    old_to_new[root]->random = old_to_new[root->random];

    copy_random(root->left);
    copy_random(root->right);
  }

  NodeCopy* copyRandomBinaryTree(Node* root)
  {
    deepcopy(root);
    copy_random(root);

    return old_to_new[root];
  }
};
