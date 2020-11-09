class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minval = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minval = min(prices[i], minval);
            profit = max(profit, prices[i] - minval);
        }
        return profit;
    }
};