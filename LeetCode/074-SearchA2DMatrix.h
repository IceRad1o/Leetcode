#include <vector>
using std::vector;
class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int i = 0;
        int j = m * n - 1;
        while (i <= j) {
            int mid = (i + j) >> 1;
            int y = mid % n;
            int x = mid / n;
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return false;
    }
};

void test74()
{
    vector<int> v{1,1};
    vector<vector<int>> mat;
    mat.push_back(v);
    Solution74 s74;
    s74.searchMatrix(mat, 2);
}