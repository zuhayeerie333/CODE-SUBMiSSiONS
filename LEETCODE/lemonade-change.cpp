class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int cnt_five = 0;
        int cnt_ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                cnt_five++;
            if (bills[i] == 10)
            {
                if (cnt_five)
                {
                    cnt_five--;
                    cnt_ten++;
                }
                else
                    return false;
            }
            if (bills[i] == 20)
            {
                if (cnt_five && cnt_ten)
                {
                    cnt_five--;
                    cnt_ten--;
                }
                else if (cnt_five >= 3)
                    cnt_five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};
