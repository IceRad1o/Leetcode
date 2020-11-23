
// 1. 重开一个数组，遍历A  2. 原地交换
class Solution922{
public:

    // 原地交换
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        for (int i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 == 1) {
                while (j < A.size() && A[j] % 2 != 0) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }
        return A;
    }

    // 1
    vector<int> sortArrayByParityII_v1(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int i = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] % 2 == 0) {
                ans[i] = A[j];
                i += 2;
            }
        }
        i = 1;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] % 2 == 1) {
                ans[i] = A[j];
                i += 2;
            }
        }
        return ans;
    }
};