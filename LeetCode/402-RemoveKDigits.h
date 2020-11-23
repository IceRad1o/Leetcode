#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution402 {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (int i = 0; i < num.size(); i++) {
            int n = num[i] - '0';
            while (k && !stk.empty() && n < stk.back() - '0') {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }
        while (k) {
            stk.pop_back();
            k--;
        }
        string res = "";
        bool leadzero = true;
        for (int i = 0; i < stk.size(); i++) {
            if (leadzero && stk[i] == '0') {
                continue;
            }
            leadzero = false;
            res.push_back(stk[i]);
        }
        return res == "" ? "0" : res;
    }
};

void test402()
{
    string str = "11111111";
    Solution402 s402;
    s402.removeKdigits(str, 3);
}