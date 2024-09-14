class Solution
{
    string str;
    unordered_map<string, int> mp;
    int sz;
    vector<vector<string>> res;
private:
    void dfs(string word, vector<string> &seq)
    {
        if (word == str)
        {
            reverse(seq.begin(), seq.end());
            res.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for (int i = 0; i < sz; i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        str = beginWord;
        mp[str] = 1;
        queue<string> q;
        q.push({str});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(str);
        sz = str.size();
        while (q.size())
        {
            string word = q.front();
            q.pop();
            int steps = mp[word];
            if (word == endWord)
                break;
            for (int i = 0; i < sz; i++)
            {
                char org = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = org;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return res;
    }
};
