//
// Created by Suhas Reddy on 2/14/25.
//

//greedy solution ->roughly bigO(n)
class Solution
{
public:
  int jump(vector<int>& nums)
  {
    int left=0, right=0;

    int steps=0;

    while(right<nums.size()-1)
    {
      auto farthest =0;

      for(int i=left; i<=right; i++) //determines the max position we can reach from every index starting left.
      {
        farthest = max(farthest, i+nums[i]);
      }

      left = right+1;
      right = farthest;

      steps++;
    }
    return steps;
  }
};
