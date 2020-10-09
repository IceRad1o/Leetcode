#include<string>
using std::string;

class Solution08 {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        int result = 0;
        if (str.size() == 0) return 0;
        int len = str.size();
        while (i < len && str[i] == ' ') {
            i++;
        }
        if (i < len && (str[i] == '+' || str[i] == '-')) {
            sign = str[i++] == '+' ? 1 : -1;
        }
        while (i < len && isdigit(str[i])) {
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (str[i++] - '0');
        }

        return result * sign;
    }
};