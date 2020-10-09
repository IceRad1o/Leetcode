#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::cout;
using std::endl;

class Solution40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        dfs(candidates, path, ret, target, 0);
        return ret;
    }

    void dfs(vector<int>& candidates, vector<int>& path, vector<vector<int>>& ret, int target, int begin)
    {
        if (target == 0) {
            ret.push_back(path);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (i > begin&& candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            //cout << "µÝ¹éÇ°: ";
            //for (auto i : path) { cout << i << " "; }
            //cout << endl;
            dfs(candidates, path, ret, target - candidates[i], i + 1);
            //cout << "µÝ¹éºó: ";
            //for (auto i : path) { cout << i << " "; }
            //cout << endl;
            path.pop_back();
        }
    }
};

void test40()
{
    vector<int> t = { 10,1,2,7,6,1,5 };
    Solution40 s40;
    vector<vector<int>> result = s40.combinationSum2(t, 8);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}