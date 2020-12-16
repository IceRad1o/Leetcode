class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxwindow;
        deque<int> index;
        const int n = nums.size();
        if (n == 0) return maxwindow;
        for (int i = 0; i < k; ++i) {
            while (!index.empty() && nums[i] >= nums[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }
        for (int i = k; i < n; ++i) {
            maxwindow.push_back(nums[index.front()]);
            while (!index.empty() && nums[i] >= nums[index.back()]) {
                index.pop_back();
            }
            while (!index.empty() && index.front() < i - k + 1) {
                index.pop_front();
            }
            index.push_back(i);
        }
        maxwindow.push_back(nums[index.front()]);
        return maxwindow;
    }
};