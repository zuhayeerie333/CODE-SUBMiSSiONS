// class implemented
/*
struct Item
{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool cmp(Item &x, Item &y)
    {
        return (double)x.value / x.weight > (double)y.value / y.weight;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        double res_total = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= w)
            {
                res_total += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {
                res_total += (double)arr[i].value * (double)w / arr[i].weight;
                break;
            }
        }
        return res_total;
    }
};
