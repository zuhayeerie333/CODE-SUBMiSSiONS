class Solution
{
public:
    string findOrder(string dict[], int n, int k)
    {
        vector<int> adj[k];
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> inDeg(k, 0);
        for (int i = 0; i < k; i++)
        {
            for (auto it : adj[i])
                inDeg[it]++;
        }
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            if (inDeg[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while (q.size())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto it : adj[node])
            {
                inDeg[it]--;
                if (inDeg[it] == 0)
                    q.push(it);
            }
        }
        string res_str = "";
        for (auto it : res)
            res_str += char(it + 'a');
        return res_str;
    }
};
