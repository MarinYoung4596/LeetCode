/*
23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "ListNode.h" 
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.empty()) return nullptr;

		vector<ListNode*> MinHeap;
		ListNode savedHead(-1);
		ListNode *curr = &savedHead;
		unordered_set<int> indexOfNullptr;
		for (auto i = 0, flag = 0; flag < lists.size(); ++i, i %= lists.size())
		{
			if (nullptr == lists[i])
			{
				if (indexOfNullptr.find(i) != indexOfNullptr.end()) continue;
				indexOfNullptr.insert(i);
				++flag;
				continue;
			}
			MinHeap.push_back(lists[i]);
			//push_heap(MinHeap.begin(), MinHeap.end(), CmpByValue());

			lists[i] = lists[i]->next;
		}
		make_heap(MinHeap.begin(), MinHeap.end(), CmpByValue());
		while (!MinHeap.empty())
		{
			pop_heap(MinHeap.begin(), MinHeap.end(), CmpByValue()); // pop heap top
			curr->next = MinHeap[MinHeap.size() - 1];
			MinHeap.pop_back();
			curr = curr->next;
			curr->next = nullptr;
			if (nullptr == savedHead.next) savedHead.next = curr;
		}
		return savedHead.next;
	}


private:
	struct CmpByValue
	{
		bool operator()(ListNode *lhs, ListNode *rhs) const
		{
			return lhs->val > rhs->val;
		}
	};
};


int main()
{
	ListNode *h1 = constructList({ 1, 6 });
	ListNode *h2 = constructList({ 2, 4, 9 });
	ListNode *h3 = constructList({ 3, 5, 7, 8 });
	ListNode *h4 = constructList({ 0, 10 });
	ListNode *h5 = constructList({ 11 });
	vector<ListNode*> test1 = { h1, h2, h3, h4, h5 };

	ListNode *h6 = constructList({ -2, -1, -1, -1 });
	ListNode *h7 = nullptr;
	vector<ListNode*> test2 = { h6, h7 };

	ListNode *h8 = constructList({ -10, -9, -9, -9, -7, -2, -1, 2, 4 });
	ListNode *h9 = constructList({ -9, -7, -6, -6, -3, 0, 1, 3 });
	ListNode *h0 = constructList({ -10, -9, -2, -1, 1, 3 });
	vector<ListNode*> test3 = { h8, h9, h0 };

	ListNode *h11 = constructList({ 6, 7, 8 });
	ListNode *h12 = constructList({ 1, 3, 5, 7, 9 });
	ListNode *h13 = constructList({ -1, 0, 1, 1, 1, 1, 1, 1, 1 });
	vector<ListNode*> test4 = { h11, h12, h13 };

	ListNode *h14 = constructList({ -1, -1, -1 });
	ListNode *h15 = constructList({ -2, -2, -1 });
	vector<ListNode*> test5 = { h14, h15 };

	Solution obj;

	printList(obj.mergeKLists(test1));
	printList(obj.mergeKLists(test2));
	printList(obj.mergeKLists(test3));
	printList(obj.mergeKLists(test4));
	printList(obj.mergeKLists(test5));


	system("pause");
	return 0;
}