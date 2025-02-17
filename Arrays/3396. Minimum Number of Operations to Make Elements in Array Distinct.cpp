//
// Created by Suhas Reddy on 2/15/25.
//

// find the last duplicate element in array iterating from last. all the elements until that point
// needs to be deleted

class Solution {
public:
  int minimumOperations(vector<int>& nums)
  {
    vector<int> freq(101, 0);
    for(int i = nums.size()-1; i >= 0; --i)
    {
      if(++freq[nums[i]] > 1)
        return ceil((double)(i + 1)/3); //i+1 as indexing starts at 0.
    }
    return 0;
  }
};
