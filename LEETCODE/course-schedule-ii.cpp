class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[numCourses];
        for (auto it : prerequisites)
            adj[it[1]].push_back(it[0]);
        vector<int> inDeg(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
                inDeg[it]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
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
        if (res.size() == numCourses)
            return res;
        return {};
    }
};
