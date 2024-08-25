class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 > N2)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0;
        int r = N1;
        int lf_req = (N1 + N2 + 1) / 2;
        int N3 = N1 + N2;
        double res = -1;
        while (l <= r)
        {
            int M1 = (l + r) / 2;
            int M2 = lf_req - M1;
            int L1 = INT_MIN;
            int L2 = INT_MIN;
            int R1 = INT_MAX;
            int R2 = INT_MAX;
            if (M1 < N1)
                R1 = nums1[M1];
            if (M2 < N2)
                R2 = nums2[M2];
            if (M1 > 0)
                L1 = nums1[M1 - 1];
            if (M2 > 0)
                L2 = nums2[M2 - 1];
            if (L1 <= R2 && L2 <= R1)
            {
                if (N3 % 2)
                    res = max(L1, L2);
                else
                {
                    int MDN = max(L1, L2) + min(R1, R2);
                    res = MDN / 2.0;
                }
                return res;
            }
            else if (L1 > R2)
                r = M1 - 1;
            else
                l = M1 + 1;
        }
        return -1;
    }
};
