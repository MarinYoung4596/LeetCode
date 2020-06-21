#ifndef _LISTNODE_H_
#define _LISTNODE_H_
#include <vector>
#include <iostream>
#include <initializer_list>

class ListNode {
public:
    ListNode() {}

    explicit ListNode(int x) : value(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *p) : value(x), next(p) {}

    template <typename T>
    friend ListNode* construct_list(std::vector<T> nums);

    friend void print_list(ListNode *head);

public:
    int value;
    ListNode* next;
};


template <typename Iter>
ListNode* construct_list(Iter begin, Iter end) {
    ListNode head(-1);
    ListNode *p = &head;
    for (auto it = begin; it != end; ++it) {
        p->next = new ListNode(*it);
        p = p->next;
    }
    return head.next;
}

template <typename T>
ListNode* construct_list(const std::vector<T> &nums) {
    return construct_list(nums.begin(), nums.end());
}

template <typename T>
ListNode* construct_list(const std::initializer_list<T> &il) {
    return construct_list(il.begin(), il.end());
}

void print_list(ListNode* head) {
    for (ListNode *p = head; p != nullptr; p = p->next) {
        std::cout << p->value << '\t';
    }
    std::cout << std::endl;
}
#endif // _LISTNODE_H_
