/*
Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:
        1
       / \
      2   5
     / \   \
    3   4   6
    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
    Input: root = []
    Output: []

Example 3:
    Input: root = [0]
    Output: [0]


Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100


Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/

#include <iostream>
#include <stack>

#include "TreeNode.h"

// pre-order traversal
// First Solution: iteractive, stack
class Solution {
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            if (p->right != nullptr) {
                s.push(p->right);
            }
            if (p->left != nullptr) {
                s.push(p->left);
            }

            p->left = nullptr;
            if (!s.empty()) {
                p->right = s.top();    // Ensure the link list to be completed.
            }
        }
    }
};


// Second Solution: recursive
class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        flatten(root->left);
        flatten(root->right);

        // 后序遍历。前面已经将左右子树节点拍平了

        auto left = root->left;  // 暂存左右节点
        auto right = root->right;

        root->left = nullptr;
        root->right = left;  // 先插入左子树

        auto p = root;
        while (p->right != nullptr) {  // 遍历到原左子树最右侧节点（即链表的末尾，因为左子树已经拍平了）
            p = p->right;
        }
        p->right = right;  // 拼接右子树
    }
};

int main(int argc, char **argv) {
    /*
            1            push    stack    pop
           / \           (9)     | 6 |    (10)
          2   5                  | 3 |    (6)
         / \   \                 | 4 |    (7)
        3   4   6        (4)     | 2 |    (5)
                         (3)     | 5 |    (8)
                         (1)     | 1 |    (2)
    */
    TreeNode *root = new TreeNode(1);
    TreeNode *p = root;
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->right->right = new TreeNode(6);

    p = p->left;
    p->left = new TreeNode(3);
    p->right = new TreeNode(4);

    Solution obj;
    obj.flatten(root);

    for (auto i = root; i != nullptr; i = i->right) {
        std::cout << i->val << '\t';
    }
    std::cout << std::endl;

    return 0;
}
