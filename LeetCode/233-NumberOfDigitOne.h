class Solution233 {
public:
    int countDigitOne(int n) {
        int counter = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divide = i * 10;
            counter += n / divide * i + min(max(n % divide - i + 1, 0LL), i);
        }
        return counter;
    }
};