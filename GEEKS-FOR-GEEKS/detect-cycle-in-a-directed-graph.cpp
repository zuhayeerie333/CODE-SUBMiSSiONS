class Solution
{
private:
    bool dfs(int i, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[i] = 1;
        pathVis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pathVis) == true)
                    return true;
            }
            else if (pathVis[it])
                return true;
        }
        pathVis[i] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (dfs(i, adj, vis, pathVis) == true)
                    return true;
        }
        return false;
    }
};
