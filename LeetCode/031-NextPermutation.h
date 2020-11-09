#include<vector>
#include<algorithm>
using std::vector;

class Solution31 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >i && nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i],nums[j]);
        }
        std::reverse(nums.begin()+i+1, nums.end());
    }
private:
    /*
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }        
    */

};