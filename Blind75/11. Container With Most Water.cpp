//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  int maxArea(vector<int>& height)
  {
    int max_area = 0;
    int left = 0, right = height.size()-1;

    while(left<right)
    {
      int width = right-left;
      int area = min(height[left], height[right])*width;

      max_area=max(max_area, area);

      if(height[left]<=height[right])
        left++;
      else
        right--;
    }

    return max_area;
  }
};