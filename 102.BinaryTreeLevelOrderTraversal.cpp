/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
	3
   / \
  9  20
 / \
15  7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "TreeNode.h"

using namespace std;

// First Solution: Double Queue
// see: http://www.acmerblog.com/leetcode-solution-binary-tree-level-order-traversal-6275.html
// or: https://github.com/soulmachine/leetcode/tree/master/C%2B%2B
// or: http://www.cnblogs.com/miloyip/archive/2010/05/12/binary_tree_traversal.html
vector<vector<int>> levelOrder(TreeNode *root)
{
	vector<vector<int>> res;
	if (root == nullptr) return res;

	vector<int> level;
	queue<TreeNode *> q, next;
	q.push(root);
	while (!q.empty())
	{
		while (!q.empty())
		{
			TreeNode *node = q.front();
			q.pop();
			level.push_back(node->val);
			if (node->left) next.push(node->left);
			if (node->right) next.push(node->right);
		}
		res.push_back(level);
		level.clear();
		std::swap(next, q);
	}
	return res;
}


// Second Solution: set mark of end
// see: http://www.cnblogs.com/miloyip/archive/2010/05/12/binary_tree_traversal.html
vector<vector<int>> levelOrder_2(TreeNode *root)
{
	vector<vector<int>> res;
	if (root == nullptr) return res;

	vector<int> level;
	queue<TreeNode *> q;

	q.push(root);
	q.push(nullptr);	// set nullptr as the end mark of each level
	while (!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();
		if (node != nullptr)
		{
			level.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		else if (!q.empty())// q is not empty
		{
			q.push(nullptr);
			res.push_back(level);
			level.clear();
		}
	}
	res.push_back(level);
	return res;
}


// Third Solution: Recursion
// see: http://www.acmerblog.com/leetcode-solution-binary-tree-level-order-traversal-6275.html
void traverse(TreeNode *root, size_t level, vector<vector<int>> &res)
{
	if (root == nullptr) return;
	if (level > res.size())
		res.push_back(vector<int>());	// push_back a new level

	res[level - 1].push_back(root->val);
	traverse(root->left, level + 1, res);
	traverse(root->right, level + 1, res);
}

vector<vector<int> > levelOrder_3(TreeNode *root)
{
	vector<vector<int> > res;
	traverse(root, 1, res);
	return res;
}


int main(int argc, char **argv)
{
	/*
	       1
	      / \
	     2	 7
		/ \	  \
	   3   4   8
		  / \
		 5   6
	*/
	TreeNode *root = new TreeNode(1);
	TreeNode *p = root;
	p->left = new TreeNode(2);
	p->right = new TreeNode(7);

	TreeNode *q = p->right;
	q->right = new TreeNode(8);

	p = p->left;
	p->left = new TreeNode(3);
	p->right = new TreeNode(4);

	p = p->right;
	p->left = new TreeNode(5);
	p->right = new TreeNode(6);

	vector<int> vp = postorderTraversal_2(root);
	for (auto i = vp.begin(); i != vp.end(); ++i)
		cout << *i << '\t';
	cout << endl;

	vector<vector<int> > vl = levelOrder_2(root);
	for (size_t i = 0; i < vl.size();  ++i)
	{
		for (auto j = vl[i].begin(); j != vl[i].end(); ++j)
			cout << *j << '\t';
		cout << endl;
	}

	return 0;
}
