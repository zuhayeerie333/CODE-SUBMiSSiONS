// DFS-METHOD !!

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



// BFS-METHOD !!

class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        int inDeg[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                inDeg[it]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDeg[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (q.size())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                inDeg[it]--;
                if (inDeg[it] == 0)
                    q.push(it);
            }
        }
        if (cnt == V)
            return false;
        return true;
    }
};
