/*
Given a complete binary tree, count the number of nodes.

Note:
    Definition of a complete binary tree from Wikipedia: http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
    In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input:
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/

// First Solution: pre-order traversal
// Runtime: 72 ms, faster than 6.98% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 30.8 MB, less than 53.86% of C++ online submissions for Count Complete Tree Nodes.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        ++result;
        countNodes(root->left);
        countNodes(root->right);
        return result;
    }

private:
    int result;
};


// Second Solution:
