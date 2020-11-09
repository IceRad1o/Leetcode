class Solution {
public:
    unordered_map<char, string> umap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"} };

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path;
        if (digits.size() == 0) return res;
        dfs(0, digits, path, res);
        return res;
    }

    void dfs(int index, string& digits, string& path, vector<string>& res) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        char c = digits[index];
        for (int i = 0; i < umap[c].size(); i++) {
            path.push_back(umap[c][i]);
            dfs(index + 1, digits, path, res);
            path.pop_back();
        }
    }
};