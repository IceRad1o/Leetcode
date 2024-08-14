//
// Created by jialei on 2023/9/19.
//


#include <iostream>
#include <vector>

using namespace std;


bool canJump(vector<int>& nums) {
        int len = nums.size();
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i], nums[i-1]-1);
            if(nums[i] + i + 1 >= len){
                return true;
            }
        }
        return false;
    }


int main() {
    // Write C++ code here
    vector<int> nums = {3,2,1,0,4};
    canJump(nums);

    return 0;
}