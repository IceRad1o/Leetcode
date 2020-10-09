class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> uset;
        int ret = 0, i = 0, j = 0;
        const int n = s.size();
        while (i < n && j < n) {
            if (uset.find(s[j]) == uset.end()) {
                uset.insert(s[j++]);
                ret = max(ret, j - i);
            }
            else {
                uset.erase(s[i++]);
            }
        }
        return ret;
    }
};