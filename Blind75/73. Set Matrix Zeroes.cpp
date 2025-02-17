//
// Created by Suhas Reddy on 2/15/25.
//

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool rowzero = false, colzero = false;

    // Check if first row contains any zero
    for (int c = 0; c < cols; c++) {
      if (matrix[0][c] == 0) {
        rowzero = true;
        break;
      }
    }

    // Check if first column contains any zero
    for (int r = 0; r < rows; r++) {
      if (matrix[r][0] == 0) {
        colzero = true;
        break;
      }
    }

    // Mark zeroes in the first row and column
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        if (matrix[r][c] == 0) {
          matrix[r][0] = 0;
          matrix[0][c] = 0;
        }
      }
    }

    // Set the matrix cells to zero based on markers
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        if (matrix[r][0] == 0 || matrix[0][c] == 0) {
          matrix[r][c] = 0;
        }
      }
    }

    // Update first column if needed
    if (colzero) {
      for (int r = 0; r < rows; r++) {
        matrix[r][0] = 0;
      }
    }

    // Update first row if needed
    if (rowzero) {
      for (int c = 0; c < cols; c++) {
        matrix[0][c] = 0;
      }
    }
    return;
  }
};
