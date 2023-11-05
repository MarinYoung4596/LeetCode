/*
Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/
#include <vector>
#include <queue>

#include "TreeNode.h"

// binary tree level order traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> _queue;
        TreeNode *back = nullptr;

        _queue.push(root);
        _queue.push(nullptr); // set nullptr as the end mark of each level
        while (!_queue.empty()) {
            TreeNode *node = _queue.front();
            _queue.pop();    // pop front
            if (node != nullptr) {
                back = node;
                if (node->right) {
                    _queue.push(node->right);
                }
            } else if (!_queue.empty()) {
                _queue.push(nullptr);
                res.push_back(back->val);
            }
        }
        res.push_back(back->val);
        return res;
    }
};