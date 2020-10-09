class Solution79 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = dfs(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& str, int k)
    {
        if (board[i][j] != str[k]) return false;
        else if (k == str.size() - 1) return true;
        visited[i][j] = 1;
        bool result = false;
        vector<pair<int, int>> directions = { {0,-1},{0,1},{1,0},{-1,0} };
        for (auto dir : directions) {
            int newx = i + dir.first;
            int newy = j + dir.second;
            if (newx >= 0 && newx < board.size() && newy >= 0 && newy < board[0].size()) {
                if (!visited[newx][newy]) {
                    bool flag = dfs(board, visited, newx, newy, str, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }


};