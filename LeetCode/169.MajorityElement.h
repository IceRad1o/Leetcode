class Solution169 {
public:
    // Map, Sort, Vote

    // Vote
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int recentN = 0;
        for (auto n : nums) {
            if (count == 0) {
                recentN = n;
            }
            count += (n == recentN ? 1 : -1);
        }
        return recentN;
    }
};