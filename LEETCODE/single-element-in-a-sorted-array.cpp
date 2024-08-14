class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[N - 2] != nums[N - 1])
            return nums[N - 1];
        int l = 1;
        int r = N - 2;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m - 1] != nums[m] && nums[m] != nums[m + 1])
                return nums[m];
            if ((m % 2 == 0 && nums[m] == nums[m + 1])
             || (m % 2 == 1 && nums[m] == nums[m - 1]))
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};
