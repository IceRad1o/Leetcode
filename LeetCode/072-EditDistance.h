#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution72 {
public:
    // dp[i-1][j-1] 存储 s1[0..i] 和 s2[0..j] 的最小编辑距离 使用dp table
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }


    // 暴力解法，会导致超时，因为这里涉及了重复的情况,可以加入备忘录来优化
    int dp(string word1, string word2, int i, int j) {
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;

        if (word1[i] == word2[j])
            return dp(word1, word2, i - 1, j - 1);
        else {
            int a1 = dp(word1, word2, i, j - 1) + 1; // insert
            int b1 = dp(word1, word2, i - 1, j) + 1; // delete
            int c1 = dp(word1, word2, i - 1, j - 1) + 1; // replace
            return minimum(a1, b1, c1);
        }
    }

    int minimum(int x, int y, int z) { return min(x, min(y, z)); }
private:
    // vector<vector<int>> _memento;
};

void test72() {
    Solution72 s;
    string str1("ho");
    string str2("r");
    cout << s.minDistance(str1, str2) << "\n";
}