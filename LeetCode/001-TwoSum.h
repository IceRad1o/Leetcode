#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.find(nums[i]) != umap.end()) {
                res.push_back(i);
                res.push_back(umap[nums[i]]);
                return res;
            }
            else umap[target - nums[i]] = i;
        }
        return res;
    }
};