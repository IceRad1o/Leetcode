#include <vector>
using std::vector;

class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(0, target, 0, candidates, tmp, ret);
        return ret;
    }
    void dfs(int sum, int target, int idx, vector<int> &candidates, vector<int> &tmp, vector<vector<int>> &ret) {
        if (sum == target) {
            ret.push_back(tmp);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (i < idx) {
                continue;
            }
            tmp.push_back(candidates[i]);
            idx = i;
            dfs(sum + candidates[i], target, idx, candidates, tmp, ret);
            tmp.pop_back();
        }
    }
};

// 如果不想排序又想避免 2 3 2 这样的情况，最好是用一个idx，只能重复当前或者idx更往后的元素，避免吃回头草
void test39() {
    vector<int> t = {2, 3, 6, 7};
    Solution39 s39;
    s39.combinationSum(t, 7);
}