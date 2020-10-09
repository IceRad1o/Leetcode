#include<limits.h>

class Solution7 {
public:
    int reverse(int x) {
        // -2147483648~2147483647
        int rev = 0;
        while (x != 0) {
            int p = x % 10;
            x = x / 10;
            if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && p > INT_MAX % 10) return 0;
            if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && p < INT_MIN % 10) return 0;
            rev = rev * 10 + p;
        }
        return rev;
    }
};