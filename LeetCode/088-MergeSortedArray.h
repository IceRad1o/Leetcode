class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = m + n - 1;
        while (m && n) {
            if (nums1[m - 1] < nums2[n - 1]) {
                nums1[t--] = nums2[n - 1];
                n--;
            }
            else {
                nums1[t--] = nums1[m - 1];
                m--;
            }
        }
        if (m == 0) {
            while (n) {
                nums1[t--] = nums2[n - 1];
                n--;
            }
        }
        else {
            while (m) {
                nums1[t--] = nums1[m - 1];
                m--;
            }
        }
        return;
    }
};