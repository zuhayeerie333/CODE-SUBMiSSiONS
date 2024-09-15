class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        while (pq.size())
        {
            int DIST = pq.top().first;
            int NODE = pq.top().second;
            pq.pop();
            for (auto it : adj[NODE])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (DIST + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = DIST + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = NODE;
                }
            }
        }
        if (dist[n] == INT_MAX)
            return {-1};
        vector<int> res_path;
        int NODE = n;
        while (parent[NODE] != NODE)
        {
            res_path.push_back(NODE);
            NODE = parent[NODE];
        }
        res_path.push_back(1);
        res_path.push_back(dist[n]);
        reverse(res_path.begin(), res_path.end());
        return res_path;
    }
};
