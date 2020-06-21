/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include "TreeNode.h"

// DFS Solution
int minDepth(TreeNode *root) {
	if (root == nullptr) {
		return 0;
    } else if (root->left == nullptr && root->right == nullptr) {
		return 1;
    }

	int left = INT_MAX;
	int right = INT_MAX;		// for the case that root->left or root->right is nullptr
	if (root->left) {
		left = minDepth(root->left) + 1;	// 1 represents "root"
    }
    if (root->right) {
		right = minDepth(root->right) + 1;
    }
	return std::min(left, right);
}
