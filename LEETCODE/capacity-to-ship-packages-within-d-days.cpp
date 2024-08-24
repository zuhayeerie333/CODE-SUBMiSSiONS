class Solution
{
private:
    bool is_possible(vector<int> weights, int days, int m)
    {
        int cnt = 1;
        int tmp = m;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] <= tmp)
                tmp -= weights[i];
            else
            {
                cnt++;
                tmp = m - weights[i];
                if (cnt > days)
                    return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int res = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (is_possible(weights, days, m))
            {
                res = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return res;
    }
};
