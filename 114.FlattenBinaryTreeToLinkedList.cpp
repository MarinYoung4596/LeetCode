/*
114. Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:
1->2->3->4->5->6
*/

#include <iostream>
#include <stack>

#include "TreeNode.h"

// pre-order traversal
// First Solution: stack
void flatten(TreeNode *root)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode *p = s.top();
		s.pop();
		if (p->right != nullptr) s.push(p->right);
		if (p->left != nullptr) s.push(p->left);
		p->left = nullptr;
		if (!s.empty())
			p->right = s.top();	// Ensure the link list to be completed.
	}
}

int main(int argc, char **argv)
{
	/*
		    1			push	stack	pop
		   / \			(9)		| 6 |	(10)
		  2   5					| 3 |	(6)
		 / \   \				| 4 |	(7)
		3   4   6		(4)		| 2 |	(5)
						(3)		| 5 |	(8)
						(1)		| 1 |	(2)
	*/
	TreeNode *root = new TreeNode(1);
	TreeNode *p = root;
	p->left = new TreeNode(2);
	p->right = new TreeNode(5);
	p->right->right = new TreeNode(6);
	
	p = p->left;
	p->left = new TreeNode(3);
	p->right = new TreeNode(4);

	flatten(root);

	for (auto i = root; i != nullptr; i = i->right)
		std::cout << i->val << '\t';
	std::cout << std::endl;

	// Windows
	system("pause");
	return 0;
}
