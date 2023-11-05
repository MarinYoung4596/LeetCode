/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <vector>
#include <stack>

#include "TreeNode.h"

using namespace std;

// First Solution: Recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        postOrder(root, res);
        return res;
    }

private:
    void postOrder(TreeNode *root, vector<int> &v) {
        if (root->left != nullptr) postOrder(root->left, v);
        if (root->right != nullptr) postOrder(root->right, v);
        v.push_back(root->val);
    }
};


// Second Solution: STACK
// Time Complexity: O(N), Space Complexity: O(N)
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> s;
        TreeNode *p = root;        // current visit
        do {
            while (p != nullptr) {
                s.push(p);
                if (p->left != nullptr) p = p->left;
                else p = p->right;
            }
            while (!s.empty() && s.top()->right == p) {
                p = s.top();
                s.pop();
                res.push_back(p->val);
            }
            if (!s.empty()) {
                p = s.top()->right; // important
            }
        } while (!s.empty());
        return res;
    }
};