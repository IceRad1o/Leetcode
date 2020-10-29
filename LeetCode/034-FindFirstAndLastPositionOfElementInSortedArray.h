#include<vector>
using std::vector;

class Solution34 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int leftindex = searchExtremeRange(nums, target, true);
        int rightindex = searchExtremeRange(nums, target, false);
        if (leftindex != -1) {
            v.push_back(leftindex);
            v.push_back(rightindex);
        }
        else {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }

    int searchExtremeRange(vector<int>& nums, int target, bool left)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                if (left) j = mid - 1;
                else i = mid + 1;
            }
            else if (nums[mid] > target) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        if (left) {
            // ���ص�Ӧ����leftֵ
            // Ҫע��û���ҵ������ 1.������Ԫ�ض������ʱ�� [j,i] i��Խ���˵� 2.������Ԫ�ض�С��j=-1,i��0
            if (i < nums.size() && nums[i] == target) { return i; }
            else return -1;
        }
        else {
            // ���ص�Ӧ����rightֵ
            if (j >= 0 && nums[j] == target) { return j; }
            else return -1;
        }
    }
};

void test34()
{
    vector<int> nums{ 5,7,7,8,8,10 };
    int target = 8;
    Solution34 s34;
    s34.searchRange(nums,target);
}