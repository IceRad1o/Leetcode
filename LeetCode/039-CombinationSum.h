#include<vector>
using std::vector;

// 这里candidates里的元素是独一无二的
class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        dfs(candidates, path, ret, 0, target, 0);
        return ret;
    }

    void dfs(vector<int>& candidates, vector<int>& path, vector<vector<int>>& ret, int cursum, int target, int level)
    {
        if (cursum == target) {
            ret.push_back(path);
        }
        if (cursum > target) {
            return;
        }
        for (int i = level; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, path, ret, cursum + candidates[i], target, level);
            path.pop_back();
            level++;
        }
    }
};


void test39()
{
    vector<int> t = { 2,3,6,7 };
    Solution39 s39;
    s39.combinationSum(t, 7);
}