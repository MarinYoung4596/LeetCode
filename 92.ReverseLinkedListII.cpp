/*
92. REVERSE LINKED LIST II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include "ListNode"


ListNode *reverseBetween(ListNode *head, int m, int n) {
	if (head == nullptr) {
        return nullptr;
    }
	if (m == n) {
        return head;
    }
	ListNode savehead(0);
	savehead.next = head;
	/*
	Index	1	->		  m				n		 ->Len
	List	Head->......->x->y->......->z->......->Tail
	*PROCESS:
	List:	head->...->	1	->	2	->	3	->	4	->	5	......->Tail
	1					p		r
	2				   pre	<-	p		r
	3							pre	<-	p		r
	4									pre	<-	p		r
	*CODE:
	SCAN:		pre = p;	p = r;	r = r->next;
	REVERSE:	p->next = pre;
	*/
	ListNode *p = &savehead;
	for (int i = 0; i < m-1; ++i) {
		p = p->next;
    }

	ListNode *preM = p;	// preM	->	NODE(M-1)
	p = preM->next;		// p	->	NODE(M)
	ListNode *M = p;	// M	->	NODE(M) save the position of M
	ListNode *r = p->next;//r	->	NODE(M+1)
	for (int i = m; i < n && r != NULL; ++i) {
		ListNode *pre = p;
		p = r;
		r = r->next;	// SCAN

		p->next = pre;	// REVERSE
	}
	preM->next = p;		// NODE(M-1)	->	NODE(N)
	M->next = r;		// NODE(M)		->	NODE(N+1)

	return savehead.next;
}


int main(int argv, char **argc) {
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	ListNode* p = new ListNode(A[0]);
	ListNode* head = p;
	for (int i = 1; i < 10; i++) {
		p->next = new ListNode(A[i]);
		p = p->next;
	}
	print_list(head);
	p = reverseBetween(head, 4, 8);
	print_list(p);

	return 0;
}
