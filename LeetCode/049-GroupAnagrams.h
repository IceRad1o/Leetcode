class Solution49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> umap;
        string tmp;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(strs[i]);
        }
        for (auto m : umap) {
            ret.push_back(m.second);
        }
        return ret;
    }
};