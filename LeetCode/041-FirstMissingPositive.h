#include<vector>
using std::vector;
class Solution41 {
public:
    // ԭ��hash
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                nums[i] = len + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);
            if (index <= len) {
                nums[index - 1] = -abs(nums[index - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return len + 1;
    }

    // hashmap ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(n)
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> umap;
        int len = nums.size();  // ֻ��Ҫ����len���ȼ��ɵ�
        for (int num : nums) {
            if (umap.find(num) == umap.end()) {
                umap[num] = 1;
            }
        }
        for (int i = 1; i <= len; i++) {
            if (umap.find(i) == umap.end()) {
                return i;
            }
        }
        return len + 1;
    }
};