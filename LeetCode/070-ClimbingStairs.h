class Solution70 {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int* dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
/*
 LC上是一个简单的爬楼梯问题。
 有很多相关的变种问题可以看下
 如果每次爬楼梯是1到k次都可以呢？
*/