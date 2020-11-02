#include<string>
#include<vector>
using std::string;
using std::vector;
class Solution6 {
public:
    string convert(string s, int numRows) {
       // if (numRows == 1) return s;
        vector<string> rows(min(numRows, static_cast<int>(s.size())));
        int row = 0;
        bool inc = true;
        for (int i = 0; i < s.size(); i++) {
            rows[row].push_back(s[i]);
            if (row == 0) inc = true;
            else if (row == numRows - 1) inc = false;
            row += inc ? 1 : -1;
        }
        string res = "";
        for (string s : rows) {
            res += s;
        }
        return res;
    }
};

void test6() {
    string str = "ABC";
    Solution6 s6;
    s6.convert(str, 1);
}