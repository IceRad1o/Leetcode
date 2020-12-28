class Solution994 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int counter = 0;
        queue<pair<int, int> >rotted;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    rotted.push({ i,j });
                }
                if (grid[i][j] == 1) {
                    counter++;
                }
            }
        }
        if (counter == 0) {
            return 0;
        }
        vector<pair<int, int> > directions = { {1,0}, {-1,0}, {0,1}, {0,-1} };
        int time = 0;
        while (!rotted.empty()) {
            int size = rotted.size();
            while (size--) {
                pair<int, int> r = rotted.front();
                rotted.pop();
                for (auto dir : directions) {
                    int newx = r.first + dir.first;
                    int newy = r.second + dir.second;
                    if (0 <= newx && newx < grid.size() && 0 <= newy &&
                        newy < grid[0].size() && grid[newx][newy] == 1) {
                        counter--;
                        grid[newx][newy] = 2;
                        rotted.push({ newx, newy });
                    }
                }
            }
            time++;
            if (counter == 0) {
                break;
            }
        }
        if (counter != 0) {
            return -1;
        }
        return time;
    }
};