#include <queue>
#include <unordered_set>
using std::unordered_set;
using std::queue;
class Solution127{
public:
    // ���͵�bfs��������������ĸ���࣬��������Ҫerase����lc�лᳬʱ��ʹ�ö����visited�����жϾͿ���ͨ��
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

    int ladderLength_v2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int len = beginWord.size();
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string str = q.front();
                if (str == endWord) return level;
                q.pop();
                for (int i = 0; i < len; i++) {
                    char c = str[i];
                    for (int j = 0; j < 26; j++) {
                        str[i] = 'a' + j;
                        if (str[i] == c) continue;
                        if (uset.find(str) != uset.end() && visited.find(str) == visited.end()) {
                            q.push(str);
                            visited.insert(str);
                        }
                    }
                    str[i] = c;
                }

            }
            level++;
        }
        return 0;
    }
};