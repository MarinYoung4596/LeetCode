/*
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
*/
#include <vector>
#include "TreeNode.h"

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> res;
	if (root == nullptr)
		return res;

	vector<int> path;
	int currSum = 0;
	findPath(root, sum, path, currSum, res);
}

void findPath(TreeNode *root, int sum, vector<int> &path, int currSum, vector<vector<int>> &res)
{
	currSum += root->val;
	path.push_back(root->val);

	if ((root->left == nullptr && root->right == nullptr)
		&& currSum == sum)
	{
		res.push_back(path);
	}

	// else
	if (root->left != nullptr)
		findPath(root->left, sum, path, currSum, res);
	if (root->right != nullptr)
		findPath(root->right, sum, path, currSum, res);

	path.pop_back(); // back to the parent node
}