#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
class Solution10 {
public:
    void print(vector<vector<int>>& dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto match = [&](int i, int j)->bool {
            if (i == 0) return false;
            if (p[j - 1] == '.') return true;
            return s[i - 1] == p[j - 1];
        };
        vector<vector<int>> dp(s.size() + 1, (vector<int>(p.size() + 1, 0)));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {  // jth character of p
                    dp[i][j] |= dp[i][j - 2];
                    if (match(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
                else {
                    if (match(i, j)) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
            }
            print(dp);

        }
        return dp[m][n];
    }
};

void test10() {
    string s = "aab";
    string p = "c*a*b";
    Solution10 s10;
    s10.isMatch(s, p);
}