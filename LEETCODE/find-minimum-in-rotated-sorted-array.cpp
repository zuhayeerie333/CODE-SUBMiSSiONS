class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int res_min = INT_MAX;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[l] <= nums[m])
            {
                res_min = min(res_min, nums[l]);
                l = m + 1;
            }
            else
            {
                res_min = min(res_min, nums[m]);
                r = m - 1;
            }
        }
        return res_min;
    }
};
