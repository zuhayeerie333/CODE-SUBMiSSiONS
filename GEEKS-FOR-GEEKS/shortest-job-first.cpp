class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());
        int time = 0;
        int w_time = 0;
        for (int i = 0; i < bt.size() - 1; i++)
        {
            time += bt[i];
            w_time += time;
        }
        return w_time / bt.size();
    }
};
