//
// Created by Suhas Reddy on 2/17/25.
//

//Check the max length obtained trying each node as parent.

class Solution {
public:

  int longestpath = 0;
  //diameter = calculate left subtree height and right subtree height passing through //every node. the one with maximum length is diameter.
  int getdiameter(TreeNode* node)
  {
    if(node == nullptr)
      return 0;

    int lh = getdiameter(node->left);
    int rh = getdiameter(node->right);

    longestpath = max(longestpath, lh+rh);//longest path passing through this node as root
    return 1+max(lh, rh);// longest path considering this as in path

  }
  int diameterOfBinaryTree(TreeNode* root)
  {
    if(root == nullptr)
      return longestpath;

    getdiameter(root);
    return longestpath;
  }
};

// Follow-up printing path along.
class Solution2 {
public:
  int longestPath = 0;
  vector<TreeNode*> longestDiameterPath;

  struct PathInfo {
    int height;
    vector<TreeNode*> path;
  };

  PathInfo getDiameterPath(TreeNode* node)
  {
    if (node == nullptr)
      return {0, {}};

    PathInfo left = getDiameterPath(node->left);
    PathInfo right = getDiameterPath(node->right);

    // Store the longest path passing through the current node
    int localDiameter = left.height + right.height;
    if (localDiameter > longestPath) {
      longestPath = localDiameter;
      longestDiameterPath = left.path;  // Copy left path
      longestDiameterPath.push_back(node);
      longestDiameterPath.insert(longestDiameterPath.end(), right.path.begin(), right.path.end());
    }

    // Choose the longer path and add current node
    if (left.height > right.height) {
      left.path.push_back(node);
      return {left.height + 1, left.path};
    } else {
      right.path.push_back(node);
      return {right.height + 1, right.path};
    }
  }

  int diameterOfBinaryTree(TreeNode* root)
  {
    if (root == nullptr)
      return 0;
    getDiameterPath(root);

    return longestPath;
  }
};

