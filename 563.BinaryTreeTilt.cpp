/*
Given a binary tree, return the tilt of the whole tree.
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input:
         1
       /   \
      2     3
Output: 1
Explanation:
    Tilt of node 2 : 0
    Tilt of node 3 : 0
    Tilt of node 1 : |2-3| = 1
    Tilt of binary tree : 0 + 0 + 1 = 1


Note:
    The sum of node values in any subtree won't exceed the range of 32-bit integer.
    All the tilt values won't exceed the range of 32-bit integer.
*/


class Solution {
public:
    int findTilt(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode* root, int &tilt) {
        if (nullptr == root) {
            return 0;
        }
        auto left_sum = dfs(root->left, tilt);
        auto right_sum = dfs(root->right, tilt);
        tilt += abs(left_sum - right_sum);
        return left_sum + right_sum + root->val;
    }
};