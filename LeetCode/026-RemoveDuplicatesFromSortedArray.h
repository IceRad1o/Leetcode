#include<iterator>

class Solution26 {
public:
    // two pointer. 
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[count] != nums[i]) {
                nums[++count] = nums[i];
            }
        }
        return count + 1;
    }

    // STL
};