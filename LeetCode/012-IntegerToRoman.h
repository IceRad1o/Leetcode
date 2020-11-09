class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> romans{ "M", "CM", "D", "CD", "C", "XC", "L",
                              "XL", "X", "IX", "V", "IV", "I" };
        int index = 0;
        string res;
        while (index < 13) {
            while (num >= nums[index]) {
                res += romans[index];
                num -= nums[index];
            }
            index++;
        }
        return res;
    }
};