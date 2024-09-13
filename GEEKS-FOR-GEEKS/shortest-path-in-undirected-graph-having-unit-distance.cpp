class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> res_dist(N, INT_MAX);
        res_dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (q.size())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (res_dist[node] + 1 < res_dist[it])
                {
                    res_dist[it] = res_dist[node] + 1;
                    q.push(it);
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
