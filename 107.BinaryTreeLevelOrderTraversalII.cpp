/*
107. Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its bottom-up level order traversal as:
    [
        [15,7],
        [9,20],
        [3]
    ]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        traverse(root, 1, res);
        std::reverse(res.begin(), res.end());    // only add this line compared with  <Binary Tree Level Order Traversal>
        return res;
    }

private:
    void traverse(TreeNode *root, size_t level, vector<vector<int>> &res) {
        if (root == nullptr) {
            return;
        }
        if (level > res.size()) {
            res.push_back(vector<int>());    // push_back a new level
        }
        res[level - 1].push_back(root->val);
        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);
    }
};
