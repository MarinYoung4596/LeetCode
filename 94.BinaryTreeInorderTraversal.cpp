/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
    1
   / \
  2   3
 /
4
 \
  5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/

#include <iostream>
#include <vector>
#include <stack>

#include "TreeNode.h"

using namespace std;

// First Solution: Recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        inOrder(root, res);
        return res;
    }

private:
    void inOrder(TreeNode *root, vector<int> &v) {
        if (root->left != nullptr) {
            inOrder(root->left, v);
        }
        v.push_back(root->val);
        if (root->right != nullptr) {
            inOrder(root->right, v);
        }
    }
};

// Second Solution: STACK
// Time Complexity: O(N), Space Complexity: O(N)
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p != nullptr || !s.empty()) {
            if (p != nullptr) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};