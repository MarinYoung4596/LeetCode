/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include "TreeNode.h"

// First Solution:  dfs
class Solution {
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int left = INT_MAX;
        int right = INT_MAX;        // for the case that root->left or root->right is nullptr
        if (root->left) {
            left = minDepth(root->left) + 1;    // 1 represents "root"
        }
        if (root->right) {
            right = minDepth(root->right) + 1;
        }
        return min(left, right);
    }
};

// Second Solution:  bfs
class Solution2 {
    int minDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        auto depth = 1;
        while (!q.empty()) {
            auto queue_len = q.size();
            for (auto i = 0; i < queue_len; ++i) {
                auto node = q.front();
                q.pop();
                if (nullptr == node->left && nullptr == node->right) { // 从上到下第一个叶子节点
                    return depth;
                }
                if (nullptr != node->left) {
                    q.push(node->left);
                }
                if (nullptr != node->right) {
                    q.push(node->right);
                }
            }
            ++depth;
        }
        return depth;
    }
};
