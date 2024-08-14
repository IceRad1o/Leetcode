#include <iostream>
#include <string>
#include <sstream>
#include "002.AddTwoNumbers.h"
#include "004-MedianofTwoSortedArrays.h"
#include "005-LongestPalindromicSubstring.h"
#include "006-ZigzagConversion.h"
#include "008-atoi.h"
#include "010-RegularExpressionMatching.h"
#include "015-3Sum.h"
#include "032-LongestValidParentheses.h"
#include "034-FindFirstAndLastPositionOfElementInSortedArray.h"
#include "039-CombinationSum.h"
#include "040-CombinationSum2.h"
#include "054-SpiralMatrix.h"
#include "059-SpiralMatrix2.h"
#include "067.AddBinary.h"
#include "072-EditDistance.h"
#include "076-MinimumWindowSubstring.h"
#include "074-SearchA2DMatrix.h"
#include "082-RemoveDuplicatesFromSortedList2.h"
#include "086-PartitionList.h"
#include "113-PathSum2.h"
#include "114-FlatenBinaryTreeToLinkedList.h"
#include "125-ValidPalindrome.h"
#include "134-GasStation.h"
#include "148-SortList.h"
#include "155-MinStack.h"
#include "200-NumberOfIslands.h"
#include "215-KthLargestElementinanArray.h"
#include "206-ReverseLinkedList.h"
#include "224-BasicCalculator.h"
#include "227-BasicCalculator2.h"
#include "322-CoinChange.h"
#include "327-CountOfRangeSum.h"
#include "349-IntersectionOfTwoArrays.h"
#include "402-RemoveKDigits.h"
#include "925-LongPressedName.h"
#include "941-ValidMountainArray.h"

using namespace std;

ListNode* createLinkedList() {
	ListNode* start = new ListNode(1);
	start->next = new ListNode(2);
	start->next->next = new ListNode(3);
	start->next->next->next = new ListNode(4);
	start->next->next->next->next = new ListNode(5);
	return start;
}

void test82() {
	Solution82 s82;
	ListNode* start = createLinkedList();
	ListNode* testlist = s82.deleteDuplicates(start);
	while (testlist) {
		cout << testlist->val << " ";
		testlist = testlist->next;
	}
}

void test86(int x) {
	ListNode* start = createLinkedList();
	Solution86 s86;
	ListNode *testlist = s86.partition(start, x);
	while (testlist) {
		cout << testlist->val << " ";
		testlist = testlist->next;
	}
}

void test125() {
	string test1("A man, a plan, a canal: Panama");
	string test2(",.");
	Solution125 s125;
	bool result = s125.isValidPalindrome(test2);
	cout << result << endl;
}

void test206() {
	ListNode* start = createLinkedList();
	Solution206 s206;
	ListNode *testlist = s206.reverseList(start);
	while (testlist) {
		cout << testlist->val << " ";
		testlist = testlist->next;
	}
}

int trap(vector<int>& height) {
	int res = 0;
	int maxLeft = 0;
	int maxRight = 0;
	stack<int> stk;
	for (int i = 1; i < height.size() - 1; i++) {
		int j = i - 1;
		while (j >= 0) {
			maxLeft = max(maxLeft, height[j]);
			j--;
		}
		int k = i + 1;
		while (k < height.size()) {
			maxRight = max(maxRight, height[k]);
			k++;
		}
		if (maxLeft <= height[i] || maxRight <= height[i]) {
			res += 0;
			continue;
		}
		res += min(maxLeft, maxRight) - height[i];
	}
	return res;
}

vector<int> rain{ 0,1,0,2,1,0,1,3,2,1,2,1 };

int main(){

	test39();
    /*
	vector<string> test;
	string path = "/a/./b/../../c/";
	stringstream ss(path);
	string tmp;
	while (getline(ss, tmp, '/')) {
		test.push_back(tmp);
	}
	for (auto s : test) {
		cout << s << endl;
	}
	//trap(rain);
	string str = "abc";
	reverse(str.begin() + 1, str.begin() + 2);
	//str.erase(str.begin() + 1, str.begin()+3);
	cout << str << endl;

    int a, b =-1;
    std::cout << a << b << std::endl;
     */
}