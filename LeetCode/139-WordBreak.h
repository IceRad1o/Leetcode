class Solution139 {
public:
    // ��̬�滮 ʱ�临�Ӷȸ� O(n*n) ����n���ַ���n+1���ָ��
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

    // TODO Trie����˼·?
};