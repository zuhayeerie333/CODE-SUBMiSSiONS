class Solution
{
private:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adjLs[node])
        {
            if (!vis[it])
                dfs(it, adjLs, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int N = isConnected.size();
        vector<int> adjLs[N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(N, 0);
        int cnt_provinces = 0;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                cnt_provinces++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt_provinces;
    }
};
