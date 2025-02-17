//
// Created by Suhas Reddy on 2/14/25.
//

//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    int curr_min, curr_max, result;

    curr_min = curr_max = result = nums[0];

    for (int i = 1; i < nums.size(); i++) {

      auto tmp_max =
          max(nums[i], max(curr_max * nums[i], curr_min * nums[i]));

      curr_min =
          min(nums[i], min(curr_min * nums[i], curr_max * nums[i]));

      // Update curr_max after updating curr_min to avoid
      // overwriting it
      curr_max = tmp_max;

      result = max(curr_max, result);
    }

    return result;
  }
};