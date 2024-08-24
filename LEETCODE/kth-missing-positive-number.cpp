class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0;
        int r = arr.size() - 1;
        int res = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int cnt_missing = arr[m] - (m + 1);
            if (cnt_missing < k)
            {
                res = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return res + k + 1;
    }
};
