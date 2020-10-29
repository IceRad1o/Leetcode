#include<string>
using std::string;

class Solution925 {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            }
            else return false;
        }
        return i == name.size();
    }
};
// 
void test925(){
    Solution925 s925;
    string testcase[] = {"alex", "aaleex"};
    s925.isLongPressedName(testcase[0], testcase[1]);
}