class Solution
{
public:
  int findCircleNum(vector<vector<int>> &arr)
  {
    int n = arr.size();
    int ans = 0;
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[i][j] && i != j)
        {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        ans += 1;
        dfs(i, adj, vis);
      }
    }
    return ans;
  }

  void dfs(int node, vector<int> adj[], vector<int> &vis)
  {
    vis[node] = 1;
    for (auto x : adj[node])
    {
      if (!vis[x])
        dfs(x, adj, vis);
    }
  }
};