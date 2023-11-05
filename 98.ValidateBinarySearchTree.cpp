/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

#include <vector>
#include <stack>
#include "TreeNode.h"


// First Solution: in-order traversal
class Solution {
    public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr
                || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }
        // 中序遍历
        vector<int> _inorder;
        stack<TreeNode *> _stack;
        TreeNode *p = root;
        while (p != nullptr || !_stack.empty()) {
            if (p != nullptr) {
                _stack.push(p);
                p = p->left;
            } else {
                p = _stack.top();
                _stack.pop();
                _inorder.push_back(p->val);
                p = p->right;
            }
        }
        // 判断是否合法
        size_t i = 0;
        for (size_t j = 1; j < _inorder.size(); ++i, ++j) {
            if (_inorder[i] >= _inorder[j]) {
                return false;
            }
        }
        return true;
    }
};

// Second Solution: recursive + dfs
class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, nullptr, nullptr);
    }

private:
    bool dfs(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (nullptr == root) {
            return true;
        }
        if (nullptr != min && root->val < min->val) {
            return false;
        }
        if (nullptr != max && root->val > max->val) {
            return false;
        }
        auto left_valid = dfs(root->left, min, root); // 左子树，root就是最大值
        auto right_valid = dfs(root->right, root, max); // 右子树，root就是最小值
        return left_valid && right_valid;
    }
};