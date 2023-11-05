#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_
#include <vector>
#include <iostream>
#include <initializer_list>

class ListNode {
public:
    ListNode() {}

    explicit ListNode(int x) : value(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *p) : value(x), next(p) {}

    friend ListNode* construct_list(std::vector<int> nums);

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

ListNode* construct_list(const std::vector<int> &nums) {
    return construct_list(nums.begin(), nums.end());
}

ListNode* construct_list(const std::initializer_list<int> &il) {
    return construct_list(il.begin(), il.end());
}

void print_list(ListNode* head) {
    for (ListNode *p = head; p != nullptr; p = p->next) {
        std::cout << p->value << '\t';
    }
    std::cout << std::endl;
}

size_t get_list_length(ListNode* head) {
    size_t result = 0;
    while (head != nullptr) {
        head = head->next;
        ++result;
    }
    return result;
}

ListNode* reverse_list(ListNode* head) {
    if (nullptr == head || nullptr == head->next) {
        return head;
    }
    auto pre = head;
    auto cur = pre->next;
    pre->next = nullptr;   // 不能缺失，否则组成一个环
    while (cur != nullptr) {
        auto next = cur->next;

        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

#endif // _LIST_NODE_H_
