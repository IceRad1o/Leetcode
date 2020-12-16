#include "utility.h"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> wordcount;
        for (string str : words) {
            wordcount[str]++;
        }
        int num = words.size();
        int len = words[0].size();
        for (int i = 0; i < s.size() - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (wordcount.find(word) != wordcount.end()) {
                    seen[word]++;
                    if (seen[word] > wordcount[word]) {
                        break;
                    }
                }
                else break;
            }
            if (j == num) {
                res.push_back(i);
            }
        }
        return res;
    }
};