/*
106. Construct Binary Tree from In-order and Post-order Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree
*/
#include <vector>
#include <iostream>

#include "TreeNode.h"
#include "postorderTraversal.cpp"

using namespace std;

TreeNode* inPostBuild(vector<int> &inorder, int inFirst, int inLast, vector<int> &postorder, int postFirst, int postLast)
{
	TreeNode *root = new TreeNode(postorder[postLast]);

	int i = inFirst;
	for (; i < inLast && inorder[i] != root->val; i++); // suppose input are valid
	int leftLength = i - inFirst;
	int rightLength = inLast - i;

	// as for the parameter, attention, the length are equal.
	// named, inLast - inFirst == postLast - postFirst
	if (leftLength)
		root->left = inPostBuild(inorder, inFirst, i - 1, postorder, postFirst, postFirst + leftLength - 1);
	else
		root->left = nullptr;

	if (rightLength)
		root->right = inPostBuild(inorder, i + 1, inLast, postorder, postLast - rightLength, postLast - 1);
	else
		root->right = nullptr;

	return root;
}


TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
{
	if (inorder.empty() || postorder.empty())
		return nullptr;
	return inPostBuild(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}


int main()
{
	vector<int> vin({ 4, 2, 1, 5, 3, 6 });
	vector<int> vpost({ 4, 2, 5, 6, 3, 1 });

	TreeNode *root = buildTree(vin, vpost);
	vector<int> preres = preorderTraversal(root);
	// expected output: preOrder: 1 2 4 3 5 6
	for (auto i = preres.begin(); i != preres.end(); i++)
		cout << *i << '\t';
	cout << endl;

	system("pause");

	return 0;
}
