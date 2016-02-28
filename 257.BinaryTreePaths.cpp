/*
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
#include "TreeNode.h"
#include <vector>
#include <string>

// DFS Solution
vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> res;
	if (root == nullptr)
		return res;

	string str = "";
	
	getPath(root, str, res);
	return res;
}

void getPath(TreeNode *root, string str, vector<string> &res)
{
	if (!str.empty())
		str += "->";
	str += to_string(root->val);

	// leaf node
	if (root->left == nullptr && root->right == nullptr)
	{
		res.push_back(str);
		return;
	}
	// else
	if (root->left != nullptr)
		getPath(root->left, str, res);
	if (root->right != nullptr)
		getPath(root->right, str, res);
}