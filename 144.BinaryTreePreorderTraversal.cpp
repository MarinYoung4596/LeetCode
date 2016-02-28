/*
144. Binary Tree Pre-order Traversal
Given a binary tree, return the pre-order traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <vector>
#include <stack>

#include "TreeNode.h"

// First Solution: Recursion
vector<int> preorderTraversal(TreeNode *root) 
{
	vector<int> res;
	if (root == NULL)
		return res;
	preOrder(root, res);
	return res;
}

void preOrder(TreeNode *root, vector<int> &v)
{
	v.push_back(root->val);
	if (root->left != NULL) preOrder(root->left, v);
	if (root->right != NULL) preOrder(root->right, v);
}

// Second Solution: Use stack
vector<int> preorderTraversal_2(TreeNode *root)
{
	vector<int> res;
	if (root == nullptr)
		return res;
	stack<TreeNode *> s;
	TreeNode *p = root;

	s.push(p);
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		res.push_back(p->val);
		if (p->right != nullptr)	// first push right, then push left
			s.push(p->right);
		if (p->left != nullptr)
			s.push(p->left);
	}
	return res;
}
