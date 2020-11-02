class Solution139 {
public:
    // 动态规划 时间复杂度高 O(n*n) 遍历n个字符和n+1个分割点
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        for (auto str : wordDict) {
            uset.insert(str);
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && uset.find(s.substr(j, i - j)) != uset.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }

    // TODO Trie树的思路?
};