class Solution50 {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / pow(x, (long long)abs(n));
        else return pow(x, n);
    }
private:
    // recur
    double pow(double x, long long n) {
        if (n == 0) return 1;
        double v = pow(x, n / 2);
        if (n % 2 == 0) return v * v;
        else return v * v * x;
    }

    // non-recur
    double pow_nonrecur(double x, long long n) {
        double ans = 1;
        while (n) {
            if (n & 1 == 1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
   
};