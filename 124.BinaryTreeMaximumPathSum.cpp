/**
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:
    Input: [1,2,3]
       1
      / \
     2   3

    Output: 6


Example 2:
    Input: [-10,9,20,null,null,15,7]
     -10
     / \
    9  20
      /  \
     15  7

    Output: 42
*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        oneSideMax(root);
        return max_path_sum;
    }

private:
    int oneSideMax(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        // 思路：类似后续遍历
        int left = max(0, oneSideMax(root->left)); // 0代表不选择左子树
        int right = max(0, oneSideMax(root->right)); // 同上
        max_path_sum = max(max_path_sum, left + right + root->val); // 以当前root为【最高节点】的最大路径和
        return max(left, right) + root->val; // 单侧最大路径和
    }

private:
    int max_path_sum = INT_MIN;
};
