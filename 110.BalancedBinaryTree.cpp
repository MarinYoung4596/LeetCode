/*
110. Balanced Binary Tree.
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of
the two subtrees of every node never differ by more than 1.
*/


#include <iostream>
#include <algorithm>

#include "TreeNode.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return getDepth(root) >= 0;
    }

private:
    int getDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ld = getDepth(root->left);  // left depth
        int rd = getDepth(root->right);  // right depth
        // for the case that ld < 0, which means they are not balanced in the last recursion
        if (abs(ld - rd) > 1 || ld < 0 || rd < 0)    {
            return -1;
        }
        return max(ld, rd) + 1;
    }
}
