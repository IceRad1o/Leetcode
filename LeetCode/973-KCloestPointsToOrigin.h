class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, vector<int>>> q;
        for (int i = 0; i < K; i++) {
            int res = pow(points[i][0], 2) + pow(points[i][1], 2);
            pair p{ res, points[i] };
            q.push(p);
        }

        for (int i = K; i < points.size(); i++) {
            int res = pow(points[i][0], 2) + pow(points[i][1], 2);
            if (res < q.top().first) {
                q.pop();
                pair p{ res, points[i] };
                q.push(p);
            }
        }
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};