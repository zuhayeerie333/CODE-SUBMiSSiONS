class Solution
{
private:
    bool is_possible(vector<int> nums, int threshold, int m)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil(nums[i] * 1.0 / m);
            if (sum > threshold)
                return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int res = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (is_possible(nums, threshold, m))
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
