class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int res_idx = nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] >= target)
            {
                res_idx = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return res_idx;
    }
};
