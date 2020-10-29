class Solution89 {
public:
    // Reflect-and-prefix method
    vector<int> grayCode(int n) {
        vector<int> gc;
        gc.push_back(0);
        for (int i = 0; i < n; i++) {
            int len = gc.size();
            for (int j = len - 1; j >= 0; j--) {
                gc.push_back(gc[j] | 1 << i);
            }
        }
        return gc;
    }
};