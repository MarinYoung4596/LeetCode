/*
98.	Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
#include <vector>
#include <stack>
#include "TreeNode.h"

// in-order traversal
bool isValidBST(TreeNode* root)
{
	if (root == nullptr || 
		(root->left == nullptr && root->right == nullptr))
		return true;

	vector<int> _inorder;
	stack<TreeNode *> _stack;
	TreeNode *p = root;
	while (p != nullptr || !_stack.empty())
	{
		if (p != nullptr)
		{
			_stack.push(p);
			p = p->left;
		}
		else
		{
			p = _stack.top();
			_stack.pop();
			_inorder.push_back(p->val);
			p = p->right;
		}
	}

	size_t i = 0;
	for (size_t j = 1; j < _inorder.size(); ++i, ++j)
	{
		if (_inorder[i] >= _inorder[j])
			return false;
	}
	return true;
}