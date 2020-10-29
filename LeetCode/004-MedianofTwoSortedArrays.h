#include <vector>
#include <algorithm>
using std::vector;
using std::min;
typedef vector<int>::const_iterator it;
class Solution4 {
public:
    // O(log(m+n))
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int index1 = 0, index2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        while (true) {
            if (index1 == len1) {
                return nums2[index2 + k - 1];
            }
            if (index2 == len2) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            int half = k / 2;
            int newindex1 = min(index1 + half, len1) - 1;
            int newindex2 = min(index2 + half, len2) - 1;
            if (nums1[newindex1] >= nums2[newindex2]) {
                k -= (newindex2 - index2 + 1);
                index2 = newindex2 + 1;
            }
            else if (nums1[newindex1] < nums2[newindex2]) {
                k -= (newindex1 - index1 + 1);
                index1 = newindex1 + 1;
            }
            // else return nums1[]
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(log(m+n))
        int total = nums1.size() + nums2.size();
        if (total % 2 != 0) {
            return getKthElement(nums1, nums2, total / 2 + 1);
        }
        else {
            int res = getKthElement(nums1, nums2, total / 2) + getKthElement(nums1, nums2, total / 2 + 1);
            return res / 2.0;
        }
        return 0.0;
    }

    double findMedianSortedArrays_merge(vector<int>& nums1, vector<int>& nums2) {
        // O(m+n)
        const int m = nums1.size();
        const int n = nums2.size();
        const int len = m + n;
        int i = 0, j = 0;
        int median1 = -1, median2 = -1;
        for (int index = 0; index <= len / 2; index++) {
            median1 = median2; // use median1 to store last element(for even number)
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) { median2 = nums1[i++]; }
                else { median2 = nums2[j++]; }
            }
            else if (i < m) {
                median2 = nums1[i++];
            }
            else if (j < n) {
                median2 = nums2[j++];
            }
            // a better brief style
            /*
              if (i < m && ( j >= n || (nums1[i] <= nums2[j])) {
                    median2 = nums1[i++];
              }
              else { median2 = nums2[j++]; }
            }
            */
        }
        if (len & 0x1) {
            return median2;
        }
        else {
            return (median1 + median2) / 2.0;
        }
    }
};

void test4(){
    vector<int> t1 = { };
    vector<int> t2 = { 1 };
    Solution4 solution;
    double c = solution.findMedianSortedArrays_merge(t1, t2);
    std::cout << c;
   
}