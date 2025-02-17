//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    int rows = matrix.size(), cols = matrix[0].size();

    int left = 0, right = cols-1;
    int top =0, bottom = rows-1;

    vector<int>result;

    while(left<=right && top<=bottom)
    {
      // top (left -> right)
      for(int i=left; i<=right; i++)
      {
        result.push_back(matrix[top][i]);
      }
      top++;

      //right (top -> bottom)
      for(int i=top; i<=bottom; i++)
      {
        result.push_back(matrix[i][right]);
      }
      right--;

      if(left>right || top>bottom)
        break;

      //bottom (right -> left)
      for(int i=right; i>=left; i--)
      {
        result.push_back(matrix[bottom][i]);
      }
      bottom --;

      //left (bottom ->top)
      for(int i=bottom; i>=top; i--)
      {
        result.push_back(matrix[i][left]);
      }
      left++;


    }

    return result;
  }
};
