class Solution
{
private:
    bool is_possible(vector<int> nums, int k, int m)
    {
        int cnt = 1;
        long long int subarraySum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (subarraySum + nums[i] <= m)
                subarraySum += nums[i];
            else
            {
                cnt++;
                subarraySum = nums[i];
                if (cnt > k)
                    return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int> &nums, int k)
    {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (is_possible(nums, k, m))
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
