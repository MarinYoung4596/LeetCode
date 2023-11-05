/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  You may return any such answer.


(Note that in the examples below, all sequences are serializations of ListNode objects.)


Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.


Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]


Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]


Constraints:
The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        std::vector<int> vec;
        for (auto node = head; node != nullptr; node = node->next) {
            vec.push_back(node->val);
            auto sum = 0;
            for (int i = vec.size() - 1; i >= 0; --i) {
                sum += vec[i];
                if (sum != 0) {
                    continue;
                }
                for (int j = vec.size() - 1; j >= i; --j) {
                    vec.pop_back();
                }
                break;
            }
        }

        ListNode saved_head(0);
        ListNode* curr = &saved_head;
        for (auto i = 0; i < vec.size(); ++i) {
            curr->next = new ListNode(vec[i]);
            curr = curr->next;
        }
        return saved_head.next;
    }
};