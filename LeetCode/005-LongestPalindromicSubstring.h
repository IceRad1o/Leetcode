#include<string>
#include<vector>
#include<algorithm>
using std::string;
using std::vector;
class Solution5 {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        int dp[l][l];
        std::fill_n(&dp[0][0], l * l, 0);
       // vector会超时
       //  vector<vector<bool>> f(n, vector<bool>(n, false));  
        int maxlen = 1, start = 0;       // 注意这里maxlen=1不能设置为0，在s只有一个字符的时候直接返回
        for (int i = 0; i < n; i++) {    // [j,i]
            f[i][i] = true;
            for (int j = 0; j < i; j++) {
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && maxlen < (i - j + 1)) {   // 符合条件才能更改j的值
                    maxlen = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxlen);

    }
};