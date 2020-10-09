#include <vector>
using std::vector;

class Solution {
public:
    // dfs
    std::vector<std::vector<int> > subsets(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
        std::vector<int> vec;
        dfs(res, nums, vec, 0);
        return res;
    }

    // Cascading method
    vector<vector<int>> subsets_cascading(vector<int>& nums) {
        vector<vector<int>> ret(1, vector<int>());
        vector<int> v;
        for (auto num : nums) {
            int m = ret.size();
            for (int i = 0; i < m; i++) {
                v = ret[i];
                v.push_back(num);
                ret.push_back(v);
            }
        }
        return ret;
    }
private:
    void dfs(std::vector<std::vector<int> >& res, std::vector<int>& nums, std::vector<int>& vec, int begin) {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i) {
            vec.push_back(nums[i]);
            dfs(res, nums, vec, i + 1);
            vec.pop_back();
        }
    }

};