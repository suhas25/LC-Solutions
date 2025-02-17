//
// Created by Suhas Reddy on 2/14/25.
//

//greedy solution
class Solution
{
  public:
    bool canJump(vector<int>& nums)
    {
      int last_index = nums.size()-1;

      for(int i=nums.size()-2; i>=0; i--)
      {
        if(i+nums[i]>=last_index)
            last_index=i;
      }
    }
    return last_index==0;
};


//O(n^2) dp solution from editorial
class Solution2 {
public:

  enum Index { GOOD, BAD, UNKNOWN };
  bool canJump(vector<int>& nums) {
    vector<Index> memo(nums.size(), UNKNOWN);
    memo[memo.size() - 1] = GOOD;
    for (int i = nums.size() - 2; i >= 0; i--) {
      int furthestJump = min(i + nums[i], (int)nums.size() - 1);
      for (int j = i + 1; j <= furthestJump; j++) {
        if (memo[j] == GOOD) {
          memo[i] = GOOD;
          break;
        }
      }
    }
    return memo[0] == GOOD;
  }
};

