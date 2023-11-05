/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
Implement these functions in your linked list class:
    get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    addAtTail(val) : Append a node of value val to the last element of the linked list.
    addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.


Example:
    Input:
        ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
        [[],[1],[3],[1,2],[1],[1],[1]]
    Output:
        [null,null,null,null,2,null,3]
    Explanation:
        MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
        linkedList.addAtHead(1);
        linkedList.addAtTail(3);
        linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
        linkedList.get(1);            // returns 2
        linkedList.deleteAtIndex(1);  // now the linked list is 1->3
        linkedList.get(1);            // returns 3


Constraints:
    0 <= index,val <= 1000
    Please do not use the built-in LinkedList library.
    At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
*/

#include <iostream>
#include <cstdio>



class MyLinkNode {
public:
    MyLinkNode(int v) : val(v), next(nullptr) {}

public:
    int val;
    MyLinkNode* next;
};

class MyLinkedList {
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    int get(int index) {
        if (index >= len) {
            return -1;
        }
        auto p = head;
        for (auto i = 0; i != index && p != nullptr; ++i) {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        auto saved_head = head;
        auto node = new MyLinkNode(val);
        node->next = saved_head;
        head = node;
        ++len;
        if (len == 1) {
            tail = head;
        }
    }

    void addAtTail(int val) {
        auto saved_tail = tail;
        auto node = new MyLinkNode(val);
        tail = node;
        if (saved_tail != nullptr) {
            saved_tail->next = node;
        }
        ++len;
        if (len == 1) {
            head = node;
        }
    }

    void addAtIndex(int index, int val) {
        if (index > len) {
            return;
        } else if (index == 0) {
            addAtHead(val);
        } else if (index == len) {
            addAtTail(val);
        } else {
            auto p = head;
            for (auto i = 0; i < index - 1 && p != nullptr; ++i) {
                p = p->next;
            }
            auto node_pre_index = p;
            auto node_index = p->next;
            auto node_index_new = new MyLinkNode(val);
            node_pre_index->next = node_index_new;
            node_index_new->next = node_index;
            ++len;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= len || index < 0) {
            return;
        } else if (index == 0) {   // 头
            auto saved_head = head;
            head = head->next;
            delete saved_head;
            --len;
        } else {
            auto p = head;
            for (auto i = 0; i < index - 1 && p != nullptr; ++i) {
                p = p->next;
            }
            auto node_pre_index = p;
            auto node_index = p->next;
            if (tail == node_index) { // 尾
                node_pre_index->next = nullptr;
                tail = node_pre_index;
            } else { // 中间
                auto node_after_index = node_index->next;
                node_pre_index->next = node_after_index;
            }
            delete node_index;
            --len;
        }
    }

private:
    int len;

    MyLinkNode* head;
    MyLinkNode* tail;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


void test1() {
    // ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get", "addAtTail"]
    // [[],[1],[3],[1,2],[1],[1],[1],[5]
    MyLinkedList linkedList = MyLinkedList(); // Initialize empty LinkedList
    linkedList.addAtHead(1);        // 1
    linkedList.addAtTail(3);        // 1, 3
    linkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    linkedList.get(1);              // returns 2
    linkedList.deleteAtIndex(1);    // now the linked list is 1->3
    linkedList.get(1);              // returns 3
    linkedList.addAtTail(5);        // 1, 3, 5
}

void test2() {
    // ["MyLinkedList",
    //    "addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex",
    //    "addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    // [[],[7],[2],[1],[3,-1],[2],[6],[4],[4],[4],[5,0],[6]]
    MyLinkedList linkedList;
    linkedList.addAtHead(7);        // 7
    linkedList.addAtHead(2);        // 2, 7
    linkedList.addAtHead(1);        // 1, 2, 7
    linkedList.addAtIndex(3, -1);   // 1, 2, 7, -1
    linkedList.deleteAtIndex(2);    // 1, 2, -1
    linkedList.addAtHead(6);        // 6, 1, 2, -1
    linkedList.addAtTail(4);        // 6, 1, 2, -1, 4
    linkedList.get(4);              // 4
    linkedList.addAtHead(4);        // 4, 6, 1, 2, -1, 4
    linkedList.addAtIndex(5, 0);    // 4, 6, 1, 2, -1, 0, 4
    linkedList.addAtHead(6);        // 6, 4, 6, 1, 2, -1, 0, 4
}

void test3() {
    // ["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
    // [[],[0,10],[0,20],[1,30],[0]]
    MyLinkedList linkedList;
    linkedList.addAtIndex(0, 10);   // 10
    linkedList.addAtIndex(0, 20);   // 20, 10
    linkedList.addAtIndex(1, 30);   // 20, 30, 10
    linkedList.get(0);              // 20
}

void test4() {
    // ["MyLinkedList","addAtHead","deleteAtIndex"]
    // [[],[1],[0]]
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.deleteAtIndex(0);
}

void test5() {
    // ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
    // [[],[1],[3],[1,2],[1],[0],[0]]
    MyLinkedList linkedList;
    linkedList.addAtHead(1);        // 1
    linkedList.addAtTail(3);        // 1, 3
    linkedList.addAtIndex(1, 2);    // 1, 2, 3
    linkedList.get(1);              // 2
    linkedList.deleteAtIndex(0);    // 2, 3
    linkedList.get(0);              // 2
}

void test6() {
    // ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead",
    //      "addAtHead","addAtHead","addAtHead","addAtHead","addAtTail",
    //      "get","deleteAtIndex","deleteAtIndex"]
    // [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]]
    MyLinkedList linkedList;
    linkedList.addAtTail(2);        // 2
    linkedList.deleteAtIndex(1);    //
    linkedList.addAtHead(2);        // 2, 2

    linkedList.addAtHead(7);
    linkedList.addAtHead(3);
    linkedList.addAtHead(2);

    linkedList.addAtHead(5);
    linkedList.addAtTail(5);
    linkedList.get(5);

    linkedList.deleteAtIndex(6);
    linkedList.deleteAtIndex(4);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}