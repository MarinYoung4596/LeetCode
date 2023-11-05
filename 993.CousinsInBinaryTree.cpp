/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.


Example 1:
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false

Example 2:
    Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
    Output: true

Example 3:
    Input: root = [1,2,3,null,4], x = 2, y = 3
    Output: false


Constraints:
    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.
*/


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        std::pair<TreeNode*, int> vx({nullptr, 0});
        dfs(root, x, nullptr, 1, vx);

        std::pair<TreeNode*, int> vy({nullptr, 0});
        dfs(root, y, nullptr, 1, vy);

        return vx.first != vy.first && vx.second == vy.second;
    }

private:
    void dfs(TreeNode* root,
             int n,
             TreeNode* parent,
             int depth,
             std::pair<TreeNode*, int> &value) {
        if (nullptr == root) {
            return;
        }
        if (root->val == n) {
            value.first = parent;
            value.second = depth;
            return;
        }
        dfs(root->left, n, root, depth + 1, value);
        // if (value.first != nullptr) {
        //     return;
        // }
        dfs(root->right, n, root, depth + 1, value);
    }
};
