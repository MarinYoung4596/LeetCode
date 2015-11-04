/*
110. Balanced Binary Tree.
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of 
the two subtrees of every node never differ by more than 1.
*/
/* @parameters:
 * @pld: previous level depth
 * @ld: left depth
 * @rd: right depth
 */
 
#include <iostream>
#include <algorithm>

#include "TreeNode.h"

using namespace std;

int getDepth(TreeNode *root)
{
	if (root == nullptr) 
		return 0;

	int ld = 1 + getDepth(root->left);
	int rd = 1 + getDepth(root->right);

	// for the case that ld == 0, which means they are not balanced in the last recursion
	if (abs(ld - rd) > 1 || !ld || !rd)	
		return -1;
	return max(ld, rd);
}


bool isBalanced(TreeNode *root)
{
	if (!root) 
		return true;
	return getDepth(root) >= 0;
}
