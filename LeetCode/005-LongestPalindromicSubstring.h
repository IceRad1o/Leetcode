#include<string>
#include<vector>
#include<algorithm>
using std::string;
using std::vector;
class Solution5 {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
       // int f[n][n];
      //  std::fill_n(&f[0][0], n*n, 0);
       // vector�ᳬʱ
        vector<vector<bool>> f(n, vector<bool>(n, false));  
        int maxlen = 1, start = 0;       // ע������maxlen=1��������Ϊ0����sֻ��һ���ַ���ʱ��ֱ�ӷ���
        for (int i = 0; i < n; i++) {    // [j,i]
            f[i][i] = true;
            for (int j = 0; j < i; j++) {
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && maxlen < (i - j + 1)) {   // �����������ܸ���j��ֵ
                    maxlen = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxlen);
    }

    // ��ͨ�õ�д����ֱ���ϸ������
    string longestPalindrome02(string s) {
        int len = s.size();
        if(len < 2) {
            return s;
        }
        int left =0,  max_len = 1;
        vector<vector<int>> dp(len, vector(len, 0));
        for(int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        // dp[i][j] 
        for(int j = 1; j < len; j++) {
            for(int i = 0; i < j; i++) {
                if(j - i == 1) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = (dp[i+1][j-1] == 1 && s[i] == s[j]) ? 1 : 0;
                }
                if(dp[i][j] == 1) {
                    if(j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        left = i;
                    }
                }
            }
        }
        return s.substr(left, max_len);
    }
};