/*
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include "TreeNode.h"

// first solution: DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto left = maxDepth(root->left) + 1;
        auto right = maxDepth(root->right) + 1;
        return std::max(left, right);
    }
};

// second solution:
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        int result = 0;
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;
        q1.push(root);

        // std::vector<std::vector<int>> levels;
        // std::vector<int> level;
        auto curr_q = &q1; // !q1.empty() ? &q1 : &q2;
        auto next_q = &q2; // !q1.empty() ? &q2 : &q1;
        while (!curr_q->empty()) {
            while (!curr_q->empty()) {
                auto node = curr_q->front();
                curr_q->pop();
                // level.push_back(node->val);

                if (node->left != nullptr) {
                    next_q->push(node->left);
                }
                if (node->right != nullptr) {
                    next_q->push(node->right);
                }
            }
            // levels.push_back(level);
            // level.clear();
            ++result;
            std::swap(curr_q, next_q);
        }
        return result;
        // return levels.size();
    }
};