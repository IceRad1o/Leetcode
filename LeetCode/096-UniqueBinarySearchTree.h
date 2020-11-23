/*
 f(n) ���Ǽ�����ÿһ���ڵ�Ϊ���ڵ����ϣ���Ƶ���������㣬ʹ��dp
 f(n) = sum(i= 0->n-1) f(i)*f(n-i-1)
 */
class Solution96 {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};