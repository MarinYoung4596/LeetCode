#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

#endif // LISTNODE_H_INCLUDED
