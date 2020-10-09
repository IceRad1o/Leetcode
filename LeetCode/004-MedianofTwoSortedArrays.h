#include <vector>
#include <algorithm>
using std::vector;
typedef vector<int>::const_iterator it;
class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(log(m+n))

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
private:
    int getKthElement(const vector<int>& nums1, int start1, int end1, \
                      const vector<int>& nums2, int start2, int end2, int k) 
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        //assume len2 > len1
        if (len1 > len2) getKthElement(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) return nums2[start2 + k - 1];
        if (k == 0) return std::min(nums1[start1], nums2[start2]);
        

    }
};

void test4(){
    vector<int> t1 = { };
    vector<int> t2 = { 1 };
    Solution4 solution;
    double c = solution.findMedianSortedArrays_merge(t1, t2);
    std::cout << c;
   
}