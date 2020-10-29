#include<vector>
using std::vector;
class Solution200 {
public:
    // 本地可以使用dfs, bfs或者union-find

    // dfs
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(column, 0));
        int ret = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '1' && visited[i][j] != 1) {
                    dfs(grid, visited, row, column, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int row, int column, int i, int j) {
        visited[i][j] = 1;
        vector<pair<int, int>> dir = { {0,1}, {0,-1},{1,0},{-1,0} };
        for (int k = 0; k < dir.size(); k++) {
            int x = i + dir[k].first;
            int y = j + dir[k].second;
            if (x >= 0 && x < row && y >= 0 && y < column && grid[x][y] == '1' && visited[x][y] == 0) {
              //  visited[x][y] = 1;
                dfs(grid, visited, row, column, x, y);
            }
        }
    }
};


void test200() {
    vector<vector<char>> grid1 = { {'1', '1', '1', '1', '0'} ,{'1', '1', '0', '1', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'} };
    vector<vector<char>> grid2 = { {'1', '1', '0', '0', '0'} ,{'1', '1', '0', '0', '0'},{'0', '0', '1', '0', '0'},{'0', '0', '0', '1', '1'} };
    Solution200 s200;
    int result1 = s200.numIslands(grid1);
    int result2 = s200.numIslands(grid2);
    cout << "result1: " << result1<<endl;
    cout << "result2: " << result2 << endl;
}