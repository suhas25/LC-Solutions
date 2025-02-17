//
// Created by Suhas Reddy on 2/14/25.
//

//MultiSource BFS along the edges.
class Solution {
public:
  void bfs(vector<vector<int>>& heights, queue<pair<int, int>>&q,
           vector<vector<int>>& reachable) {

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {
      auto [row, col] = q.front();
      q.pop();

      reachable[row][col] = 1;

      for (auto dir : directions) {
        int newrow = row + dir[0];
        int newcol = col + dir[1];

        if (newrow >= 0 && newcol >= 0 && newrow < reachable.size() &&
            newcol < reachable[0].size()) {

          if (heights[newrow][newcol] >= heights[row][col] &&
              reachable[newrow][newcol] != 1) {
            q.push({newrow, newcol});
          }
        }
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.size() == 0 || heights[0].size() == 0)
      return {};

    vector<vector<int>> pacific(heights.size(),
                                vector<int>(heights[0].size(), 0));
    vector<vector<int>> atlantic(heights.size(),
                                 vector<int>(heights[0].size(), 0));

    int rows = heights.size();
    int cols = heights[0].size();

    queue<pair<int, int>> pacific_queue;
    queue<pair<int, int>> atlantic_queue;

    for (int i = 0; i < rows; i++) {
      pacific_queue.push({i, 0});
      atlantic_queue.push({i, cols - 1});
    }

    for (int i = 0; i < cols; i++) {
      pacific_queue.push({0, i});
      atlantic_queue.push({rows - 1, i});
    }

    bfs(heights, pacific_queue, pacific);
    bfs(heights, atlantic_queue, atlantic);

    vector<vector<int>> result;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (pacific[i][j] ==1 && atlantic[i][j]==1)
          result.push_back({i, j});
      }
    }

    return result;
  }
};
