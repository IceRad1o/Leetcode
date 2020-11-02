#include<vector>
#include<algorithm>
#include<queue>
using std::vector;
using std::sort;
class Solution215 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return quickselect(nums, 0, len - 1, len - k);
    }

    int quickselect(vector<int>& nums, int left, int right, int target)
    {
       // if (left >= right) return nums[left];
        int p = partition(nums, left, right);
        if (p == target) return nums[p];
        else {
            return p > target ? quickselect(nums, left, p - 1, target) : quickselect(nums, p + 1, right, target);
        }
    }

    static int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                std::swap(a[++i], a[j]);
            }
        }
        std::swap(a[i + 1], a[r]);
        return i + 1;
    }

    // ��׼�����С��
    int findKthLargest_pq(vector<int>& nums, int k) {
        std::priority_queue <int, vector<int>, greater<int> > minq;
        for (int i = 0; i < k; i++) {
            minq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minq.top()) {
                minq.pop();
                minq.push(nums[i]);
            }
        }

        return minq.top();
    }

    /* ����ʹ��һ�±�׼�⣬��ʵ���Ե���greater<int>()�����أ������Զ����˱ȽϺ�����
    ����ע����Ϊ��Ա������һ��thisָ����Ϊ���������Բ�����sort����Σ�ʹ��static����
    static bool comp(const int& a, const int& b)
    {
        return a > b;
    }

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),comp);
        return nums[k - 1];
    }
    */
};

void test215()
{
    Solution215 s215;
    vector<int> nums{ 3,2,1,5,6,4 };
    vector<int> nums1{ 1,2 };
    cout<< s215.findKthLargest(nums1, 1);
}