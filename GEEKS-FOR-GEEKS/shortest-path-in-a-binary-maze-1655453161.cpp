class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        if (source == destination)
            return 0;
        queue<pair<int, pair<int, int>>> q;
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        while (q.size())
        {
            auto it = q.front();
            q.pop();
            int D = it.first;
            int R = it.second.first;
            int C = it.second.second;
            for (int i = 0; i < 4; i++)
            {
                int newRow = R + delRow[i];
                int newCol = C + delCol[i];
                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M)
                {
                    if (grid[newRow][newCol] == 1)
                    {
                        if (D + 1 < dist[newRow][newCol])
                        {
                            dist[newRow][newCol] = D;
                            auto it = destination;
                            if (newRow == it.first && newCol == it.second)
                                return D + 1;
                            q.push({D + 1, {newRow, newCol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
