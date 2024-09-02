// DFS-METHOD !!

class Solution
{
private:
    void dfs(int i, int vis[], stack<int> &st, vector<int> adj[])
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }
        st.push(i);
    }
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, vis, st, adj);
        }
        vector<int> res;
        while (st.size())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};



// BFS-METHOD !!

class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
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
        vector<int> res;
        while (q.size())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adj[node])
            {
                inDeg[it]--;
                if (inDeg[it] == 0)
                    q.push(it);
            }
        }
        return res;
    }
};
