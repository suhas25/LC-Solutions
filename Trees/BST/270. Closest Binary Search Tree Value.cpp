//
// Created by Suhas Reddy on 3/6/25.
//

//O(h) time and O(1) space complexity
class Solution {
public:
  int closestValue(TreeNode* root, double target)
  {
    int closest_value=root->val;
    int val=0;

    while(root!=nullptr)
    {
      val=root->val;
      if(abs(val-target)<abs(closest_value-target))
        closest_value=val;
      else if(abs(val-target)==abs(closest_value-target) && val<closest_value)
        closest_value=val;

      if(target<root->val)
        root=root->left;
      else
        root=root->right;
    }
    return closest_value;
  }
};
