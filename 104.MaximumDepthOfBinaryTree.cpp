/*
104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include "TreeNode.h"

// DFS
int maxDepth(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 1;

	int left, right;
	left = right = INT_MIN;
	if (root->left)
		left = maxDepth(root->left) + 1;
	if (root->right)
		right = maxDepth(root->right) + 1;
	return left > right ? left : right;
}

// 
int GetBTreeDepth( TreeNode *pRoot){
    if( pRoot == NULL )
        return 0;

    queue< TreeNode *> que;
    que.push( pRoot );
    int depth = 0;
    while( !que.empty() ){
        ++depth;
        int curLevelNodesTotal = que.size();
        int cnt = 0;
        while( cnt < curLevelNodesTotal ){
            ++cnt;
            pRoot = que.front();
            que.pop();
            if( pRoot->m_pLeft )
                que.push( pRoot->m_pLeft);
            if( pRoot->m_pRight)
                que.push( pRoot->m_pRight);
        }
    }
    return depth;
}