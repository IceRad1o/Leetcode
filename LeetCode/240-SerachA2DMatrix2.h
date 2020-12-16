class Solution240 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) {
                i--;
            }
            else {
                j++;
            }
        }
        return false;
    }
};