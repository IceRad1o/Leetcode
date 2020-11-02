class Solution140 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && uset.find(s.substr(j, i - j)) != uset.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        vector<string> result;
        deque<string> path;
        dfs(s, s.size(), dp, path, result, uset);
        return result;
    }

    void dfs(string s, int len, vector<bool>& dp, deque<string>& path, vector<string>& res, unordered_set<string>& uset) {
        string space = " ";
        if (len == 0) {
            string ret = "";
            for (auto s : path) {
                ret += s;
                ret += space;
            }
            ret.erase(ret.end() - 1);
            res.push_back(ret);
            return;
        }
        for (int i = len - 1; i >= 0; i--) {
            string str = s.substr(i, len - i);
            if (dp[i] && uset.count(str) != 0) {
                path.push_front(str);
                dfs(s, i, dp, path, res, uset);
                path.pop_front();
            }
        }
    }
};