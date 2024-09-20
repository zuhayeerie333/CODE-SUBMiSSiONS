class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int N = heights.size();
        int M = heights[0].size();
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        while (pq.size())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == N - 1 && col == M - 1)
                return diff;
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M)
                {
                    int newEff = max(abs(heights[row][col] - heights[newRow][newCol]), diff);
                    if (newEff < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = newEff;
                        pq.push({newEff, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};
