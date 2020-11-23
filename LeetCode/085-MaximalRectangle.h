class Solution85 {
public:
    // 3. dp，每个点的最大高度

    // 2. 用84的stack优化柱状图，给每一行计算最大矩阵


    // 1.柱状图，记录以ij为右下角的最大矩阵，记录行的最长，然后向上遍历
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int maxarea = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                }
                int width = dp[i][j];
                for (int k = i; k >= 0; k--) {
                    width = min(width, dp[k][j]);
                    maxarea = max(maxarea, width * (i - k + 1));
                }
            }
        }
        return maxarea;
    }
};