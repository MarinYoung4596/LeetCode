/*
103. Binary Tree ZigZag level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
 /     \
15      7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
#include <vector>
#include <stack>
#include "TreeNode.h"

// First Solution: Binary Tree Level Order Traversal,
// After that, traverse each line and reverse them if needed.


// Second Solution: Set a MARK to record the traversal direction,
// Whether it is left-to-right or right-to-left
// Solution 2.1 Recursion.
// @para: left_to_right: true means left to right, false means right to left
void traverse(TreeNode *root, size_t level, vector<vector<int> > &res, bool left_to_right)
{
	if (!root) return;
	if (level == res.size())
		res.push_back(vector<int>());
	if (left_to_right)
		res[level].push_back(root->val);
	else // right to left
		res[level].insert(res[level].begin(), root->val);

	traverse(root->left, level + 1, res, !left_to_right);
	traverse(root->right, level + 1, res, !left_to_right);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int> > res;
	traverse(root, 0, res, true);
	return res;
}

// Third Solution: Iterative
// 用两个栈存储当前行，下一行，自然就是zigzag的
vector<vector<int>> zigzagLevelOrder_2(TreeNode* root)
{
	vector<vector<int>> res;
	if (root == nullptr)
		return res;

	stack<TreeNode *> levels[2];
	vector<int> tmp;

	int curr = 0, next = 1;

	levels[curr].push(root);
	while (!levels[curr].empty() || !levels[next].empty())
	{
		TreeNode *pNode = levels[curr].top();
		levels[curr].pop();
		tmp.push_back(pNode->val);

		if (curr == 0)	// even level
		{
			if (pNode->left != nullptr)
				levels[next].push(pNode->left);
			if (pNode->right != nullptr)
				levels[next].push(pNode->right);
		}
		else   // odd level
		{
			if (pNode->right != nullptr)
				levels[next].push(pNode->right);
			if (pNode->left != nullptr)
				levels[next].push(pNode->left);
		}

		if (levels[curr].empty())
		{
			res.push_back(tmp);
			tmp.clear();
			curr = 1 - curr;
			next = 1 - next;
		}
	}
	return res;
}
