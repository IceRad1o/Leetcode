#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        dfs(s, ip, res, 0);
        return res;
    }
    void dfs(string& s, vector<string>& ip, vector<string>& res, int start) {
        if (ip.size() == 4 && start == s.size()) {
            string str = ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3];
            res.push_back(str);
            return;
        }

        if ((4 - ip.size()) * 3 < s.size() - start) {
            return;
        }
        if (4 - ip.size() > s.size() - start) {
            return;
        }

        int num = 0;
        for (int i = start; i < start + 3; i++) {
            num = num * 10 + s[i] - '0';
            if (num > 255) continue;
            ip.push_back(s.substr(start, i - start + 1));
            dfs(s, ip, res, i + 1);
            ip.pop_back();
            if (num == 0) break;
        }
    }
};

