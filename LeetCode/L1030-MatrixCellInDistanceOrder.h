#include "utility.h"
// 可以使用 桶排序，BFS或者几何方法
class Solution1030 {
public:
    // bfs
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        vector<vector<int>> visited(R, vector<int>(C, 0));
        vector<pair<int, int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };
        q.push({ r0,c0 });
        visited[r0][c0] = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                vector<int> p = q.front();
                int x = p[0];
                int y = p[1];
                res.push_back(p);
                q.pop();
                for (auto d : dir) {
                    int newx = d.first + x;
                    int newy = d.second + y;
                    if (newx >= 0 && newx < R && newy >= 0 && newy < C && visited[newx][newy] == 0) {
                        q.push({ newx,newy });
                        visited[newx][newy] = 1;
                    }
                }
            }
        }
        return res;
    }
};