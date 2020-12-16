#include <string>
using std::string;
// Brute force£¬KMP£¬Boyer-Mooer,Rabin-Karp
class Solution28 {
public:
    // brute_force
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        for (int i = 0; i < m - n + 1; i++) {
            int k = i;
            for (int j = 0; j < n; j++) {
                if (needle[j] != haystack[k]) {
                    break;
                }
                else k++;
            }
            if (k - i == n) return i;
        }
        return -1;
    }

    int strStr_KMP(string haystack, string needle) {

    }


};
