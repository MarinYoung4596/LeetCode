/*
105. Construct Binary Tree from Pre-order and In-order Traversal
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "inorderTraversal.cpp"

using namespace std;

TreeNode* preInBulid(
        vector<int> &preOrder, int preFirst, int preLast,
        vector<int> &inOrder, int inFirst, int inLast) {
	TreeNode *root = new TreeNode(preOrder[preFirst]);

	int i = inFirst;
	for (; inOrder[i] != root->val; i++);
	int leftLength = i - inFirst;
	int rightLength = inLast - i;
	
	if (leftLength) {
		root->left = preInBulid(
			preOrder, preFirst + 1, preFirst + leftLength,
			inOrder, inFirst, inFirst + leftLength - 1);
	} else {
		root->left = nullptr;
	}

	if (rightLength) {
		root->right = preInBulid(
			preOrder, preLast - rightLength + 1, preLast,
			inOrder, inLast - rightLength + 1, inLast);
	} else {
		root->right = nullptr;
	}

	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.empty() || inorder.empty()) {
		return nullptr;
    }

	return preInBulid(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main() {
	vector<int> vpre({ 1, 2, 4, 3, 5, 6 });
	vector<int> vin({ 4, 2, 1, 5, 3, 6 });

	TreeNode *root = buildTree(vpre, vin);
	vector<int> postres = postorderTraversal(root);
    print_vector(postres);

	return 0;
}
