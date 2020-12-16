#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using std::vector;
using std::string;
using std::stack;

class Solution32 {
public:
    // dp method
    int longestValidParentheses_dp(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (s[i] == ')' && s[i - 1] == ')') {
                int len = dp[i - 1];
                if (i - len > 0 && s[i - len - 1] == '(') {
                    dp[i] = (i - len - 2 >= 0 ? dp[i - 1] + dp[i - len - 2] + 2 : dp[i - 1] + 2);
                }
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }

    // stack method
    int longestValidParentheses(string s) {
        int maxLen = 0, last = -1;
        stack<int> lefts;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                lefts.push(i);
            }
            else {
                if (lefts.empty()) {
                    last = i;
                }
                else {
                    lefts.pop();
                    if (lefts.empty()) {
                        maxLen = std::max(maxLen, i - last);
                    }
                    else {
                        maxLen = std::max(maxLen, i - lefts.top());
                    }
                }
            }
        }
        return maxLen;
    }
};

void test32()
{
    string s("()(())");
    Solution32 s32;
    s32.longestValidParentheses(s);
}