class Solution69
{
public:
    // binary search
    int sqrt(int x) {
        // write code here
        if (x < 2) return x;
        int left = 1;
        int right = x / 2;
        int last_mid = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x / mid > mid) {
                left = mid + 1;
                last_mid = mid;
            }
            else if (x / mid < mid) {
                right = mid - 1;
            }
            else return mid;
        }
        return last_mid;
    }

    // newton method x(n+1) = x(n) - f(n)/df(n) here function: r^2-x =0
    int mySqrt_newton(int x) {
        long r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};