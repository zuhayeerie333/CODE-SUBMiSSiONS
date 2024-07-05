/*
struct Job
{
    int id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    bool static cmp(Job &x, Job &y)
    {
        return x.profit > y.profit;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        int cnt_jobs = 0;
        int tot_profit = 0;
        int max_deadline = 0;
        for (int i = 0; i < n; i++)
            max_deadline = max(max_deadline, arr[i].dead);
        vector<int> hash(max_deadline + 1, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (hash[j] == -1)
                {
                    hash[j] = 333;
                    cnt_jobs++;
                    tot_profit += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt_jobs, tot_profit};
    }
};
