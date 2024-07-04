class Solution
{
public:
    static bool cmp(vector<int> &p, vector<int> &q)
    {
        return p[1] < q[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int last_ending_time = intervals[0][1];
        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= last_ending_time)
                last_ending_time = intervals[i][1];
            else
                cnt++;
        }
        return cnt;
    }
};
