//
// Created by Suhas Reddy on 2/15/25.
//

/*
 *
 *
 *
0deg rotation : i, j will point to i, j
90deg rotation : i, j will point to j, n - i - 1
180deg rotation : i, j will point to n - i - 1, n - j - 1
270deg rotation : i, j will point to n - j - 1, i
 *
 * */

class Solution {
public:
  void rotate(vector<vector<int>>& matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i++)
    {
      for (int j = 0; j < n / 2; j++)
      {
        int temp = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
        matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }
  }
};

class Solution2 {
public:
  void rotate(vector<vector<int>>& matrix)
  {
    int left =0, right =  matrix.size()-1;

    while(left<right)
    {
      for(int i = 0; i < right - left; i++)
      {
        int top = left;
        int bottom = right;

        //save the topleft
        int topLeft = matrix[top][left + i];

        //move bottom left into top left
        matrix[top][left + i] = matrix[bottom - i][left];

        // move bottom right into bottom left
        matrix[bottom - i][left] = matrix[bottom][right - i];

        // move top right into bottom right
        matrix[bottom][right - i] = matrix[top + i][right];

        // move top left into top right
        matrix[top + i][right] = topLeft;

      }

      left++;
      right--;
    }

    return;
  }
};

//Using matrix Transpose
class Solution3 {
public:
  void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    reflect(matrix);
  }

private:
  void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[j][i], matrix[i][j]);
      }
    }
  }
  void reflect(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        swap(matrix[i][j], matrix[i][n - j - 1]);
      }
    }
  }
};