class Solution97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        if (m + n != s3.size()) {
            return false;
        }
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int t = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[t]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[t]);
                }
            }
        }
        return dp[m][n];
    }
};