#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Solution71 {
public:
    string simplifyPath(string path) {
        vector<string> res;
        stringstream sstream(path);
        string tmp;
        while (getline(sstream, tmp, '/')) {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !res.empty()) {
                res.pop_back();
            }
            else if (tmp != "..") {
                res.push_back(tmp);
            }
        }
        string unixp = "";
        for (auto str : res) {
            unixp += "/" + str;
        }
        if (res.empty()) {
            return "/";
        }
        return unixp;
    }
};