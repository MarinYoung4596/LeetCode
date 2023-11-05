/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note: You may assume that duplicates do not exist in the tree
*/

#include "TreeNode.h"

class Solution {
private:
    TreeNode* inPostBuild(
            vector<int> &inorder, int inFirst, int inLast,
            vector<int> &postorder, int postFirst, int postLast) {
        TreeNode *root = new TreeNode(postorder[postLast]);

        int i = inFirst;
        for (; i < inLast && inorder[i] != root->val; i++); // suppose input are valid
        int leftLength = i - inFirst;
        int rightLength = inLast - i;

        // as for the parameter, attention, the length are equal.
        // named, inLast - inFirst == postLast - postFirst
        if (leftLength) {
            root->left = inPostBuild(
                inorder, inFirst, i - 1,
                postorder, postFirst, postFirst + leftLength - 1);
        } else {
            root->left = nullptr;
        }
        if (rightLength) {
            root->right = inPostBuild(
                inorder, i + 1, inLast,
                postorder, postLast - rightLength, postLast - 1);
        } else {
            root->right = nullptr;
        }

        return root;
    }

public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        return inPostBuild(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
