#include "utility.h"
class Solution76 {
public:
    // use one array to act as hashtable
    string minWindow(string s, string t) {
        int cnt[128] = {};
        for (char c : t) cnt[c]++;
        int counter = t.size(), len = INT_MAX, start = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (cnt[s[r]]-- > 0) counter--;
            while (counter == 0) {
                if (r - l + 1 < len) {
                    start = l;
                    len = r - l + 1;
                }
                if (cnt[s[l++]]++ == 0) counter++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
    // use two hashtable
    string minWindow_v2(string s, string t) {
        for (char c : t) {
            tcache[c] += 1;
        }
        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1;
        while (r < (int)s.size()) {
            if (tcache.find(s[++r]) != tcache.end()) {
                scache[s[r]] ++;
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (tcache.find(s[l]) != tcache.end()) {
                    scache[s[l]] --;
                }
                l++;
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, len);
    }
private:
    bool check() {
        for (const auto& c : tcache) {
            if (scache[c.first] < c.second) {
                return false;
            }
        }
        return true;
    }
    unordered_map<char, int> tcache, scache;
};

void test76()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution76 s76;
    s76.minWindow(s, t);
}