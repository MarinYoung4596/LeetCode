/**

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.


Example 1:
    (pic)
    Input: n = 7
    Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:
    Input: n = 3
    Output: [[0,0,0]]


Constraints:
    1 <= n <= 20

 */

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;
        if (n % 2 == 0) {  // 偶数，无法构成满二叉树
            return result;
        } else if (n == 1) {
            TreeNode* root = new TreeNode(0);
            result.push_back(root);
            return result;
        }
        for (auto i = 1; i <= n - 2; i += 2) {  // ① 左右均为非偶数才能构成满二叉树，因此从1开始；
            auto left_trees = allPossibleFBT(i); // ② 左子树组合
            auto right_trees = allPossibleFBT(n - 1 - i); // ③ 右子树组合
            for (auto left : left_trees) {
                for (auto right : right_trees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};