class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int sum = prices[i] - prices[i - 1];
            if (sum > 0) profit += sum;
        }
        return profit;
    }
};