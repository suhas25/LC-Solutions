//
// Created by Suhas Reddy on 2/14/25.
//

class Solution {
public:
  void dfs(vector<vector<char>>& grid, int row, int col) {
    // checking boundaries and ensuring the cell is land, i.e, 1
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
        grid[row][col] != '1') {
      return;
    }
    grid[row][col] = '#'; // marking as visited, can use 0 , 1,2 3, whatever
                          // instead of '#'
    // exploring all directions
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
  }
  int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == '1') {
          islands++;
          dfs(grid, row, col);
        }
      }
    }
    return islands;
  }
};
