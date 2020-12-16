class Solution29 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = 1;
        if ((dividend < 0 && divisor>0) || (dividend > 0 && divisor < 0)) {
            sign = -1;
        }
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long count = 0;
        while (dvd >= dvs) {
            long long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            count += m;
        }
        return count * sign;
    }
};