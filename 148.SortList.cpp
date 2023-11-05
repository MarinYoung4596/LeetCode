/*
Sort a linked list in O(n log n) time using constant space complexity.
*/


// first Solution: merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr; // IMPORTANT: avoid endless

        return merge(sortList(head), sortList(fast));
    }

private:
    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode tmp(-1);
        ListNode* curr = &tmp;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left != nullptr) curr->next = left;
        if (right != nullptr) curr->next = right;
        return tmp.next;
    }
};

// second solution: Quick Sort
// simple swap operation, TLE in big data
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        quick_sort(head, nullptr);
        return head;
    }

private:
    void quick_sort(ListNode* head, ListNode* end) {
        if (head != end) {
            ListNode* pivot = get_partition(head, end);
            quick_sort(head, pivot);
            quick_sort(pivot->next, end);
        }
    }

    ListNode* get_partition(ListNode* head, ListNode* end) {
        auto pivot = head->val;
        ListNode* p = head;
        ListNode* q = head->next;

        for (; q != end; q = q->next) {
            if (q->val < pivot) {
                p = p->next;
                swap(p->val, q->val);
            }
        }
        swap(p->val, head->val); // put pivot at the middle position
        return p;
    }
};


// three-ways quick_sort
// see: https://discuss.leetcode.com/topic/9149/3-ways-quick_sort-o-1-sapce-cpp-solution
// and: http://www.2cto.com/kf/201401/273363.html
