#include<vector>
using std::vector;

class Solution56 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int flag = false;
        for (int i = 0; i < intervals.size(); i++) {
            int start = newInterval[0];
            int end = newInterval[1];
            if (start > intervals[i][1]) {
                ans.push_back(intervals[i]);
                continue;
            }
            if (end < intervals[i][0]) {
                ans.push_back(newInterval);
                flag = !flag;
                for (; i < intervals.size(); i++) {
                    ans.push_back(intervals[i]);
                }
                break;
            }
            newInterval[0] = min(newInterval[0], intervals[i][0]);  //区间合并
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        if (!flag) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};