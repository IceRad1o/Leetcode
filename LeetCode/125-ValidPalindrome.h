#include <string>
#include <ctype.h>
using std::string;

class Solution125
{
public:
	bool isValidPalindrome(string s)
	{
		int length = s.size();
		if (length == 0) return true;
		for (int i = 0, j = length - 1; i < j; i++, j--) {
			while (!isalnum(s[i]) && i < j) i++;
			while (!isalnum(s[j]) && i < j) j--;
			if (tolower(s[i]) != tolower(s[j])) {
				return false;
			}
		}
		return true;
	}
};