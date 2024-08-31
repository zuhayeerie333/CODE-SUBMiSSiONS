class Solution
{
private:
    bool dfs(int i, int curr_color, vector<int> &colors, vector<vector<int>> graph)
    {
        colors[i] = curr_color;
        for (auto it : graph[i])
        {
            if (colors[it] == -1)
            {
                if (dfs(it, !curr_color, colors, graph) == false)
                    return false;
            }
            else if (colors[it] == curr_color)
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int N = graph.size();
        vector<int> colors(N, -1);
        for (int i = 0; i < N; i++)
        {
            if (colors[i] == -1)
                if (dfs(i, 0, colors, graph) == false)
                    return false;
        }
        return true;
    }
};
