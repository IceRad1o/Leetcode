class Solution14 {
public:
    // ÊúÏò±È½Ï
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string str;
        int len = strs[0].size();
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return str;
                }
            }
            str.push_back(c);
        }
        return str;
    }
};