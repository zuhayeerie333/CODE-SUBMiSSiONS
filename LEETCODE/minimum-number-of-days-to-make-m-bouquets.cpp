class Solution
{
private:
    bool is_possible(vector<int> bloomDay, int m, int k, int M)
    {
        int cnt = 0;
        int tot_bouq = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= M)
                cnt++;
            else
            {
                tot_bouq += cnt / k;
                cnt = 0;
            }
            if (tot_bouq >= m)
                return true;
        }
        tot_bouq += cnt / k;
        if (tot_bouq >= m)
            return true;
        return false;
    }
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;
        while (l <= r)
        {
            int M = (l + r) / 2;
            if (is_possible(bloomDay, m, k, M))
            {
                res = M;
                r = M - 1;
            }
            else
                l = M + 1;
        }
        return res;
    }
};
