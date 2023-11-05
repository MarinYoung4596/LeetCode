/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1315.SumOfNodesWithEven-ValuedGrandparent.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/06 23:32:07
*   @brief:

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.


Example 1:
    (pic)
    Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
    Output: 18
    Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Example 2:
    Input: root = [1]
    Output: 0


Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    1 <= Node.val <= 100

*****************************************************************/


class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int &sum) {
        if (nullptr == root) {
            return;
        }
        if (root->val % 2 == 0) { // 偶数
            if (root->left != nullptr) {
                if (root->left->left != nullptr) {
                    sum += root->left->left->val;
                }
                if (root->left->right != nullptr) {
                    sum += root->left->right->val;
                }
            }
            if (root->right != nullptr) {
                if (root->right->left != nullptr) {
                    sum += root->right->left->val;
                }
                if (root->right->right != nullptr) {
                    sum += root->right->right->val;
                }
            }
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
};