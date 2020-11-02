#include <vector>
#include <unordered_set>
#include <algorithm>
using std::vector;
class Solution349 {
public:
    // Method1. using STL set or unordered_set. Unordered_set is more efficient in this problem.
    vector<int> intersection_v1(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1;
        std::unordered_set<int> set2;
        for (int i = 0; i < nums1.size(); i++) {
            set1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            set2.insert(nums2[i]);
        }
        vector<int> res;
        for (auto i : set1) {
            if (set2.find(i) != set2.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
    // Method2, Two pointer
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j]) {
                if (!res.size() || nums1[i] != res.back()) {
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                j++;
            }
        }
        return res;
    }
    // Binary Search

};

void test349()
{
    vector<int> nums1{ 4,9,5 };
    vector<int> nums2{ 9,4,9,8,4 };
    Solution349 s349;
    s349.intersection(nums1, nums2);
}