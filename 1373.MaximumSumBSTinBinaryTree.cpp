/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1373.MaximumSumBSTinBinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/12 17:32:32
*   @brief:

Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:
    Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
    Output: 20
    Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

Example 2:
    Input: root = [4,3,null,1,2]
    Output: 2
    Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

Example 3:
    Input: root = [-4,-2,-5]
    Output: 0
    Explanation: All values are negatives. Return an empty BST.

Constraints:
    The number of nodes in the tree is in the range [1, 4 * 10^4].
    -4 * 10^4 <= Node.val <= 4 * 10^4

*****************************************************************/


class Node {
public:
    bool is_bst = true;         // 当前节点为根节点时,是否是bst
    int min_value = INT_MAX;    // 所有节点的最小值
    int max_value = INT_MIN;    // 所有节点的最大值
    int value_sum = 0;          // 所有节点的和
};


class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        traverse(root, max_sum);
        return max_sum;
    }

private:
    // 类似后续遍历框架
    Node* traverse(TreeNode* root, int &max_sum) {
        if (nullptr == root) {
            return new Node();
        }
        auto left_node = traverse(root->left, max_sum);
        auto right_node = traverse(root->right, max_sum);

        auto cur_node = new Node();
        // 判断合法二叉树：左子树最大最大值 < root节点值 < 右子树最小值
        if (left_node->is_bst && right_node->is_bst
                && root->val > left_node->max_value && root->val < right_node->min_value) {
            cur_node->is_bst = true;
            cur_node->min_value = std::min(root->val, left_node->min_value);
            cur_node->max_value = std::max(root->val, right_node->max_value);
            cur_node->value_sum = root->val + left_node->value_sum + right_node->value_sum;
            max_sum = std::max(max_sum, cur_node->value_sum);
        } else {
            cur_node->is_bst = false;
        }
        return cur_node;
    }
};
