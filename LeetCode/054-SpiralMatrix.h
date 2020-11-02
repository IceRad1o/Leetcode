#include<vector>
using std::vector;
class Solution54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        if (matrix.size() == 0) return vec;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, top = 0, right = col - 1, bot = row - 1;
        while (left <= right && top <= bot) {
            for (int i = left; i <= right; i++) {
                vec.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= bot; i++) {
                vec.push_back(matrix[i][right]);
            }
            if (top != bot)
                for (int i = right - 1; i >= left; i--) {
                    vec.push_back(matrix[bot][i]);
                }
            if (left != right)
                for (int i = bot - 1; i > top; i--) {
                    vec.push_back(matrix[i][left]);
                }
            left++; right--; top++; bot--;
        }
        return vec;
    }
};

void test54()
{
    int m = 3, n = 4;
    int count = 0;
    vector<vector<int>> vec(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vec[i][j] = ++count;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
    Solution54 s54;
    s54.spiralOrder( vec);
}