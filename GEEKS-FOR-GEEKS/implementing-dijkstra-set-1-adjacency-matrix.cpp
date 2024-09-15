// PRiORiTY QUEUE METHOD !!

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res_dist(V, INT_MAX);
        res_dist[S] = 0;
        pq.push({0, S});
        while (pq.size())
        {
            int DIST = pq.top().first;
            int NODE = pq.top().second;
            pq.pop();
            for (auto it : adj[NODE])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (DIST + edgeWeight < res_dist[adjNode])
                {
                    res_dist[adjNode] = DIST + edgeWeight;
                    pq.push({res_dist[adjNode], adjNode});
                }
            }
        }
        return res_dist;
    }
};



// SET METHOD !!

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> res_dist(V, INT_MAX);
        res_dist[S] = 0;
        st.insert({0, S});
        while (st.size())
        {
            auto it = *(st.begin());
            int DIST = it.first;
            int NODE = it.second;
            st.erase(it);
            for (auto it : adj[NODE])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (DIST + edgeWeight < res_dist[adjNode])
                {
                    if (res_dist[adjNode] != INT_MAX)
                        st.erase({res_dist[adjNode], adjNode});
                    res_dist[adjNode] = DIST + edgeWeight;
                    st.insert({res_dist[adjNode], adjNode});
                }
            }
        }
        return res_dist;
    }
};
