class Solution264 {
public:
    // heap
    int nthUglyNumber(int n) {
        priority_queue <double, vector<double>, greater<double> > q;
        double answer = 1;
        for (int i = 1; i < n; ++i)
        {
            q.push(answer * 2);
            q.push(answer * 3);
            q.push(answer * 5);
            answer = q.top();
            q.pop();
            while (!q.empty() && answer == q.top()) // delete dup
                q.pop();
        }
        return answer;
    }

    // three pointer
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> res(n);
        res[0] = 1;
        int mul2 = 0, mul3 = 0, mul5 = 0;
        for (int i = 1; i < n; i++) {
            res[i] = min(min(res[mul2] * 2, res[mul3] * 3), res[mul5] * 5);
            if (res[i] == res[mul2] * 2) {
                mul2++;
            }
            if (res[i] == res[mul3] * 3) {
                mul3++;
            }
            if (res[i] == res[mul5] * 5) {
                mul5++;
            }
        }
        return res[n - 1];
    }
};