#include <iostream>
#include <string>
#include "002.AddTwoNumbers.h"
#include "004-MedianofTwoSortedArrays.h"
#include "006-ZigzagConversion.h"
#include "008-atoi.h"
#include "034-FindFirstAndLastPositionOfElementInSortedArray.h"
#include "039-CombinationSum.h"
#include "040-CombinationSum2.h"
#include "054-SpiralMatrix.h"
#include "072-EditDistance.h"
#include "082-RemoveDuplicatesFromSortedList2.h"
#include "086-PartitionList.h"
#include "113-PathSum2.h"
#include "125-ValidPalindrome.h"
#include "155-MinStack.h"
#include "200-NumberOfIslands.h"
#include "215-KthLargestElementinanArray.h"
#include "206-ReverseLinkedList.h"
#include "322-CoinChange.h"
#include "349-IntersectionOfTwoArrays.h"
#include "925-LongPressedName.h"

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



int main(){
	test349();
	return 0;
	
}