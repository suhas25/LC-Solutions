//
// Created by Suhas Reddy on 3/6/25.
//


// Inorder traversal of tree O(n) time and space complxity
class Solution
{
public:
  Node* first_node=nullptr;
  Node* last_node=nullptr;
  void dfs(Node* root)
  {
    if(root==nullptr)
      return;

    dfs(root->left);

    if(first_node==nullptr)
    {
      first_node=root;
    }

    if(last_node)
    {
      last_node->right=root;
      root->left=last_node;
    }

    last_node=root;

    dfs(root->right);
  }

  Node* treeToDoublyList(Node* root)
  {
    if(root==nullptr)
      return nullptr;

    dfs(root);
    last_node->right=first_node;
    first_node->left=last_node;

    return first_node;
  }
};