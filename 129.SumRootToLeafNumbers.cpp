/*
129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example, 
    1
   / \
  2   3



The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13. 

Return the sum = 12 + 13 = 25. 

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }

private:
    int sumNumbers(TreeNode* root, int sum)
    {
        if (nullptr == root) 
            return sum;
        if (nullptr == root->left && nullptr == root->right)
            return sum*10 + root->val;
        
        int sumLeftChild = sumNumbers(root->left, sum*10 + root->val);
        int sumRightChild = sumNumbers(root->right, sum*10 + root->val);
        
        if (nullptr == root->left)
            return sumRightChild;
        if (nullptr == root->right)
            return sumLeftChild;
        
        return sumLeftChild + sumRightChild;
    }
};