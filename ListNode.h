#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED
#include <vector>
#include <iostream>
#include <initializer_list>

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() {}

	explicit ListNode(int x) : val(x), next(nullptr) {}
	explicit ListNode(int x, ListNode *p) : val(x), next(p) {}

	template <typename T>
	friend ListNode* constructList(std::vector<T> nums);
	friend void printList(ListNode *head);
};


template <typename T>
inline ListNode* constructList(std::vector<T> nums)
{   
	ListNode head(-1);
	ListNode *p = &head;
	for (auto i = nums.begin(); i != nums.end(); ++i)
	{
		p->next = new ListNode(*i);
		p = p->next;
	}
	return head.next;
}

template <typename T>
inline ListNode* constructList(std::initializer_list<T> il)
{
	ListNode head(-1);
	ListNode *p = &head;
	for (auto it = il.begin(); it != il.end(); ++it)
	{
		p->next = new ListNode(*it);
		p = p->next;
	}
	return head.next;
}

inline void printList(ListNode *head)
{
	for (ListNode *p = head; p != nullptr; p = p->next)
	{
		std::cout << p->val << '\t';
	}
	std::cout << std::endl;
}
#endif // LISTNODE_H_INCLUDED
