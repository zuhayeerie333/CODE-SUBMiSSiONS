class Solution
{
private:
    int lowerBound(vector<int> nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int res = nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] >= target)
            {
                res = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return res;
    }
    int upperBound(vector<int> nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int res = nums.size();
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] > target)
            {
                res = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        ub--;
        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};
        return {lb, ub};
    }
};
