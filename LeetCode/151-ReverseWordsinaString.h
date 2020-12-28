class Solution151 {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                int j = i;
                while (j < n && s[j] != ' ') {
                    s[idx++] = s[j++];
                }
                reverse(s.begin() + idx - (j - i), s.begin() + idx);
                i = j;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};