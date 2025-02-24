//
// Created by Suhas Reddy on 2/21/25.
//

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat)
  {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<int>result;

    //no of diagonals is always (rows+cols-1);
    for(int i=0;i<rows+cols-1; i++)
    {
      vector<int>temp;

      int row = i<cols?0:i-cols+1;
      int col = i<cols?i:cols-1;

      while(row<rows && col>=0)
      {
        temp.push_back(mat[row][col]);
        row++, col--;
      }

      if(i%2==0)
        reverse(temp.begin(), temp.end());

      result.insert(result.end(), temp.begin(), temp.end());

    }
    return result;
  }
};
