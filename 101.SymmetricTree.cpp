/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
  1
 / \
2   2
 \   \
  3   3

Note: Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path
terminator where no node exists below.

Here's an example:
  1
 / \
2   3
   /
  4
   \
    5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}"
*/
#include <stack>
#include "TreeNode.h"


// First Solution: DFS / Recursion
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if ((left == nullptr && right != nullptr)
                || (left != nullptr && right == nullptr)) {
            return false;
        } else if (left->val != right->val) {
            return false;
        } else {
            return isSymmetric(left->left, right->right)
                && isSymmetric(left->right, right->left);
        }
    }
};

// Second Solution: Iterative / Stack
class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }

        TreeNode *p = root->left;
        TreeNode *q = root->right;

        stack<TreeNode *> s;
        s.push(p);
        s.push(q);

        while (!s.empty()) {
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();

            if (!p && !q) continue;
            if ((p && !q) || (!p && q)) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};
