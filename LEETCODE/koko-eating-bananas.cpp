class Solution
{
private:
    bool is_possible(vector<int> piles, int h, int m)
    {
        int req_time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            req_time += ceil(piles[i] * 1.0 / m);
            if (req_time > h)
                return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (is_possible(piles, h, m))
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
