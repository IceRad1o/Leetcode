#include <vector>
using std::vector;
class Solution59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int t = n * n;
        int index = 0;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (index < t) {
            for (int i = left; i <= right; i++) {
                mat[top][i] = ++index;
            }
            for (int i = top + 1; i <= bottom; i++) {
                mat[i][right] = ++index;
            }
            for (int i = right - 1; i >= left; i--) {
                mat[bottom][i] = ++index;
            }
            for (int i = bottom - 1; i > top; i--) {
                mat[i][left] = ++index;
            }
            left++; right--; top++; bottom--;
        }
        return mat;
    }
};

void test59() {
    Solution59 s59;
    s59.generateMatrix(3);
}