
// 和70爬楼梯一样，也是经典DP问题，只不过加了一些判断条件
class Solution91 {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (len == 0 || s[0] == '0') return 0;
        int cur = 1, prev = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = cur;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') cur = prev; // dp[i] = dp[i-2]
                else return 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                cur = cur + prev;  //dp[i] = dp[i-1]+dp[i-2]
            }
            else {
                cur = cur; // dp[i] = dp[i-1];
            }
            prev = tmp;
        }
        return cur;
    }
};