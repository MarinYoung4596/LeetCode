/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers.


Example 1:
     1
   /   \
  0     1
 / \   / \
0   1 0   1
Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Note:
The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
*/

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }

private:
    void dfs(TreeNode* root, int value, int &sum) {
        value = (value << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += value;
            return;
        }
        if (nullptr != root->left) {
            dfs(root->left, value, sum);
        }
        if (nullptr != root->right) {
            dfs(root->right, value, sum);
        }
    }
};
