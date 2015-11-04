/*
145. Binary Tree Post-order Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <vector>
#include <stack>

#include "TreeNode.h"

using namespace std;

// First Solution: Recursion
void postOrder(TreeNode *root, vector<int> &v)
{
	if (root->left != NULL) postOrder(root->left, v);
	if (root->right != NULL) postOrder(root->right, v);
	v.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> res;
	if (root == NULL)
		return res;
	postOrder(root, res);
	return res;
}


// Second Solution: STACK
// Time Complexity: O(N), Space Complexity: O(N)
vector<int> postorderTraversal_2(TreeNode *root)
{
	vector<int> res;
	if (root == nullptr) return res;
	stack<TreeNode *> s;
	TreeNode *p = root;		// current visit

	do {
		while (p != nullptr)
		{
			s.push(p);
			if (p->left != nullptr) p = p->left;
			else p = p->right;
		}
		while (!s.empty() && s.top()->right == p)
		{
			p = s.top();
			s.pop();
			res.push_back(p->val);
		}
		if (!s.empty())
			p = s.top()->right; // important
	} while (!s.empty());
	return res;
}
