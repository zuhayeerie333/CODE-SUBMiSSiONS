class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[N - 1] > nums[N - 2])
            return N - 1;
        int l = 1;
        int r = N - 2;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1])
                return m;
            else if (nums[m] > nums[m + 1])
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};
