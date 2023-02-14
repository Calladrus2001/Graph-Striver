class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int row = grid.size();
    int col = grid[0].size();
    int ans = 0;
    vector<vector<int>> vis(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (vis[i][j] == 0 && grid[i][j] == '1')
        {
          ans += 1;
          dfs(grid, i, j, vis);
        }
      }
    }
    return ans;
  }

  void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis)
  {
    if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size())
      return;
    if (vis[i][j] == 1 || grid[i][j] == '0')
      return;

    if (vis[i][j] == 0)
      vis[i][j] = 1;
    dfs(grid, i - 1, j, vis);
    dfs(grid, i + 1, j, vis);
    dfs(grid, i, j - 1, vis);
    dfs(grid, i, j + 1, vis);
  }
};