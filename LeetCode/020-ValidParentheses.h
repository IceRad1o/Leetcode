#include <string>
#include <stack>
#include <unordered_map>
using std::string;
using std::stack;
using std::unordered_map;
class Solution20
{
	bool isValid(string s)
	{
		unordered_map<char, char> pairs{
			{')','('},
			{']','['},
			{'}','{'} };
		stack<char> stk;
		for (auto i : s) {
			if (pairs.count(i)) {
				if (stk.empty() || pairs[i] != stk.top()) {
					return false;
				}
				stk.pop();
			}
			else
				stk.push(i);
		}
		return stk.empty();
	}
};