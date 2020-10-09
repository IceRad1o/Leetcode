#include <queue>
#include <unordered_map>

class Solution127{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int L = beginWord.size();
        int ladder = 1;
        while (!q.empty()) {
            for (int i = 0; i < q.size(); i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) return ladder;
                dict.erase(word);
                for (int j = 0; j < L; j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};