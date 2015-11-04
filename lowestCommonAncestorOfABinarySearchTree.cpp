/*
235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to
be a descendant of itself).”

	__6__
   /     \
  2       8
 / \     / \
0	4	7	9
   / \
  3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2
and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/
#include <iostream>
#include "TreeNode.h"


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr)
		return nullptr;
	if (p->val == q->val)
		return p;

	if ((p->val < root->val && root->val < q->val) ||
		(q->val < root->val && root->val < p->val))
		return root;
	else if (root->val < p->val && root->val < q->val)
		lowestCommonAncestor(root->right, p, q);
	else if (root->val > p->val && root->val > q->val)
		lowestCommonAncestor(root->left, p, q);
}


int main()
{
	TreeNode *root = new TreeNode(6);
	TreeNode *pNode2 = new TreeNode(2);
	TreeNode *pNode8 = new TreeNode(8);
	TreeNode *pNode4 = new TreeNode(4);

	root->left = pNode2;
	root->right = pNode8;

	pNode2->left = new TreeNode(0);
	pNode2->right = new TreeNode(4);

	pNode4->left = new TreeNode(3);
	pNode4->right = new TreeNode(5);

	pNode8->left = new TreeNode(7);
	pNode8->right = new TreeNode(9);

	TreeNode *x = lowestCommonAncestor(root, pNode4->left, pNode4->right);

	std::cout << x->val << std::endl;

	system("pause");
	return 0;
}