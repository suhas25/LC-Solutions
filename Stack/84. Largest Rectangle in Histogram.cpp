//
// Created by Suhas Reddy on 2/21/25.
//

/*
 * Keep on pushing into stack as long as we encounter heights in increasing order.
 * Once, we come across a smaller height, then pop until the height in stack is greater than current height
 * and keep on calculating the max area.
 * Also, update the current index to last height index popped during the iteration,
 * because area for current node can be calculated starting that index when we pop this in future.
 *
 * at the end, items left in stack means, we reached the end and its in increasing order at end.
 * Calculate the max area with remaining items again.
 * */

class Solution {
public:
  int largestRectangleArea(vector<int>& heights)
  {
    //index->height mapping.
    stack<pair<int, int>>stk;
    int max_area=0;

    for(int i=0;i<heights.size(); i++)
    {
      int start_index = i;
      while(!stk.empty() && stk.top().second>heights[i])
      {
        auto [index, height] = stk.top();
        stk.pop();

        auto width = i-index;
        start_index = index; //update the start index correctly.

        max_area = max(max_area, width*height);//

      }
      stk.push({start_index, heights[i]}); //this bar width can be calculated from the starting index start_index until when popped.
    }

    while(!stk.empty())
    {
      auto [index, height] = stk.top();
      stk.pop();

      int width = heights.size()-index;
      max_area = max(max_area, width*height);

    }

    return max_area;

  }
};
