#include<vector>

using std::vector;

class Solution47 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int len = nums.size();
        vector<vector<int>> ret;
        vector<bool> visited(len, false);
        vector<int> path;
        dfs(nums, visited, path, ret);
        return ret;
    }

    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int>>& ret)
    {
        if (path.size() == nums.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                continue;
            }
            if (visited[i] != true) {
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited, path, ret);
                visited[i] = false;
                path.pop_back();
            }

        }
    }
};