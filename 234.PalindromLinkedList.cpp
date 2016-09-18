#include <iostream>
#include <stack>
#include <vector>

#include "ListNode.h"

using namespace std;


/**

234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
 Could you do it in O(n) time and O(1) space?

*/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return true;
		if (head->next->next == nullptr)
			return head->val == head->next->val;
		
		// first solution: stack
		/*
		stack<int> s;
		int len = 0;
		for (ListNode *p = head; p != nullptr; ++len)
		s.push(p->val);

		ListNode *p = head;
		for(auto i = 0; i * 2 < len; ++i, p = p->next)
		{
		auto value = s.top();
		if(value != p->val)
		return false;
		s.pop();
		p = p->next;
		}
		return true;
		*/

		// second solution: reverse list partly
		ListNode *mid = head;
		for (ListNode *p = head; 
			p != nullptr && p->next != nullptr; 
			p = p->next->next, mid = mid->next);

		ListNode *p = mid;
		ListNode *pre = nullptr;
		ListNode *next = p->next;

		p->next = nullptr;
		for (; next != nullptr;)
		{
			pre = p;
			p = next;
			next = next->next;

			p->next = pre; // reverse
		}

		for (ListNode *pFirst = head, *pLast = p; 
			pLast != nullptr; 
			pFirst = pFirst->next, pLast = pLast->next)
		{
			if (pFirst->val != pLast->val)
				return false;
		}
		return true;
	}
};

int main(int argc, char **argv)
{
	vector<int> nums = { 2, 3, 5, 2};
	ListNode *head = constructList(nums);
	printList(head);

	Solution obj;
	std::cout << (obj.isPalindrome(head) ? "TRUE": "FALSE") << std::endl;


	system("pause");
	return 0;
}