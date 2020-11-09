#include <vector>
using std::vector;

class Solution941{
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0;
        // int len = A.size();
        while (i + 1 < A.size() && A[i + 1]>A[i]) { // why we use i+1 because A.size() return unsigned int. if A.size()=0 then it cause runtime error
            i++;
        }
        if (i + 1 == A.size() || i == 0) return false;
        while (i + 1 < A.size() && A[i]>A[i + 1]) {
            i++;
        }
        return i + 1 == A.size();
    }
};

void test941() {
    vector<int> a;
    Solution941 s941;
    s941.validMountainArray(a);
}