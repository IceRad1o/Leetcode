#include<vector>
using std::vector;

class Solution46 {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ret;
        int len = nums.size();
        vector<int> visited(len, false);
        vector<int> path;
        dfs(0, nums, visited, path, ret);
    }

    void dfs(int depth, vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int>>& ret) {
        if (depth == nums.size()) {
            ret.push_back(path);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] != true) {
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(depth + 1, nums, visited, path, ret);
                visited[i] = false;
                path.pop_back();
            }
        }
    }


    // refer to 031-NextPermutations, using that function
    // using std
    vector<vector<int>> permute_std(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }

    //
};