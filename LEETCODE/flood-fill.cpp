class Solution
{
private:
    void dfs(vector<vector<int>> image, vector<vector<int>> &res, int row, int col, int color,
             int init_color, int delrow[], int delcol[])
    {
        res[row][col] = color;
        int n = res.size();
        int m = res[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
            {
                if (image[nrow][ncol] == init_color && res[nrow][ncol] != color)
                    dfs(image, res, nrow, ncol, color, init_color, delrow, delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int init_color = image[sr][sc];
        vector<vector<int>> res = image;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        dfs(image, res, sr, sc, color, init_color, delrow, delcol);
        return res;
    }
};
