class Solution
{
private:
    void topoSort(int i, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            int v = it.first;
            if (!vis[v])
                topoSort(v, adj, vis, st);
        }
        st.push(i);
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        int vis[N] = {0};
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }
        vector<int> res_dist(N, INT_MAX);
        res_dist[0] = 0;
        while (st.size())
        {
            int node = st.top();
            st.pop();
            if (res_dist[node] != INT_MAX)
            {
                for (auto it : adj[node])
                {
                    int v = it.first;
                    int w = it.second;
                    if (res_dist[node] + w < res_dist[v])
                        res_dist[v] = res_dist[node] + w;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (res_dist[i] == INT_MAX)
                res_dist[i] = -1;
        }
        return res_dist;
    }
};
