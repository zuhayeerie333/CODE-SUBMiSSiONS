class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({end[i], start[i]});
        sort(v.begin(), v.end());
        int last_ending_time = v[0].first;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i].second > last_ending_time)
            {
                cnt++;
                last_ending_time = v[i].first;
            }
        }
        return cnt;
    }
};
