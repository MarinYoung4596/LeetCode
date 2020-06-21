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


class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList(int v = 0) : value(v), next(nullptr) {
        len = 0;
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index > size()) {
            throw "index out of range";
        }
        auto node = head;
        for (auto i = 0; i < index; ++i) {
            node = node->next;
        }
        printf("get:\tindex=%d,value=%d\thead=%d,tail=%d\n",
                index, node->value, head->value, tail->value);
        return node->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        ++len;
        printf("addAtHead:\tvalue=%d\thead=%d,tail=%d\n",
                val, head->value, tail->value, head->value, tail->value);
        print();
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        if (tail == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
        ++len;
        printf("addAtTail:\tvalue=%d\thead=%d,tail=%d\n",
                val, head->value, tail->value);
        print();
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        index = std::max(index, 0);
        index = std::min(index, len);
        if (index == 0) {
            addAtHead(val);
        } else if (index == len) {
            addAtTail(val);
        } else {
            MyLinkedList* node = new MyLinkedList(val);
            auto pre = head;
            auto cur = head;
            for (auto i = 0; i < index && cur != nullptr; ++i) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = node;
            node->next = cur;
            ++len;
        }
        printf("addAtIndex:\tindex=%d,value=%d\thead=%d,tail=%d\n",
                index, val, head->value, tail->value);
        print();
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index > size()) {
            throw "index out of range";
        } else if (head == nullptr) {
            return;
        } else if (index == 0) {
            auto tmp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete tmp;
        } else {
            auto pre = head;
            auto cur = head;
            for (auto i = 0; i < index && cur != nullptr; ++i) {
                pre = cur;
                cur = cur->next;
            }
            if (index == size()) { // delete at tail, cur->next = nullptr
                pre->next = nullptr;
                tail = pre;
                delete cur;
            } else {
                pre->next = cur->next;
            }
        }

        --len;
        printf("deleteAtIndex:\tindex=%d\tthead=%s,tail=%s\n",
                index,
                head != nullptr ? std::to_string(head->value).c_str() : "NULL",
                tail != nullptr ? std::to_string(tail->value).c_str() : "NULL");
        print();
    }

private:
    int size() const {
        return len;
    }

    void print() const {
        for (auto node = head; node != nullptr; node = node->next) {
            std::cout << node->value << '\t';
        }
        std::cout << "\n---------------------------\n";
    }

private:
    int value;
    int len;
    MyLinkedList* next;

    MyLinkedList* head;
    MyLinkedList* tail;
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
    linkedList.addAtHead(1); // 1
    linkedList.addAtTail(3); // 1, 3
    linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
    linkedList.get(1);            // returns 2
    linkedList.deleteAtIndex(1);  // now the linked list is 1->3
    linkedList.get(1);            // returns 3
    linkedList.addAtTail(5); // 1, 3, 5
}

void test2() {
    // ["MyLinkedList",
    //    "addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex",
    //    "addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    // [[],[7],[2],[1],[3,-1],[2],[6],[4],[4],[4],[5,0],[6]]
    MyLinkedList linkedList;
    linkedList.addAtHead(7);
    linkedList.addAtHead(2);
    linkedList.addAtHead(1);
    linkedList.addAtIndex(3, -1);
    linkedList.deleteAtIndex(2);
    linkedList.addAtHead(6);
    linkedList.addAtTail(4);
    linkedList.get(4);
    linkedList.addAtHead(4);
    linkedList.addAtIndex(5, 0);
    linkedList.addAtHead(6);
}

void test3() {
    // ["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
    // [[],[0,10],[0,20],[1,30],[0]]
    MyLinkedList linkedList;
    linkedList.addAtIndex(0, 10);
    linkedList.addAtIndex(0, 20);
    linkedList.addAtIndex(1, 30);
    linkedList.get(0);
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
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2);
    linkedList.get(1);
    linkedList.deleteAtIndex(0);
    linkedList.get(0);
}

void test6() {
    // ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead",
    //      "addAtHead","addAtHead","addAtHead","addAtHead","addAtTail",
    //      "get","deleteAtIndex","deleteAtIndex"]
    // [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]]
    MyLinkedList linkedList;
    linkedList.addAtTail(2);
    linkedList.deleteAtIndex(1);
    linkedList.addAtHead(2);

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
    // test1();
    // test2();

    // test3();
    // test4();
    // test5();

    test6();

    return 0;
}