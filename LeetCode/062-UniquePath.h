class Solution62 {
public:
    // 


    // recursive


    // math method : use long long to avoid integer overflow
    int uniquePaths_math(int m, int n) {
        int move = m + n - 2;
        int minval = min(m, n) - 1;
        long long fac1 = 1, fac2 = 1;
        for (long long i = minval; i > 0; i--) {
            fac1 *= i;
        }

        for (long long i = 0; i < minval; i++) {
            fac2 *= move;
            move--;
        }
        return fac2 / fac1;
    }
};

