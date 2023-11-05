/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
    Given binary tree {3,9,20,#,#,15,7},
         3
        / \
       9  20
      / \
    15  7
    return its level order traversal as:
    [
        [3],
        [9,20],
        [15,7]
    ]


Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "TreeNode.h"

using namespace std;

// First Solution: BFS;  Double Queue
// see: http://www.acmerblog.com/leetcode-solution-binary-tree-level-order-traversal-6275.html
// or: https://github.com/soulmachine/leetcode/tree/master/C%2B%2B
// or: http://www.cnblogs.com/miloyip/archive/2010/05/12/binary_tree_traversal.html
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        vector<int> level;
        queue<TreeNode *> q, next;
        q.push(root);
        while (!q.empty()) {
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    next.push(node->left);
                }
                if (node->right) {
                    next.push(node->right);
                }
            }
            res.push_back(level);
            level.clear();
            std::swap(next, q);
        }
        return res;
    }
};


// Second Solution: BFS; set nullptr as the mark of end
// see: http://www.cnblogs.com/miloyip/archive/2010/05/12/binary_tree_traversal.html
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        vector<int> level;
        queue<TreeNode *> q;

        q.push(root);
        q.push(nullptr);    // set nullptr as the end mark of each level
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node != nullptr) {
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            } else if (!q.empty()) {  // q is not empty
                q.push(nullptr);
                res.push_back(level);
                level.clear();
            }
        }
        res.push_back(level);
        return res;
    }
};

// Third Solution: BFS; queue_size
class Solution3 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (nullptr == root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto queue_len = q.size();
            vector<int> level;
            for (auto i = 0; i < queue_len; ++i) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);

                if (nullptr != node->left) {
                    q.push(node->left);
                }
                if (nullptr != node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

// Forth Solution: Recursive, DFS
// see: http://www.acmerblog.com/leetcode-solution-binary-tree-level-order-traversal-6275.html
class Solution4 {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        traverse(root, 1, res);
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
