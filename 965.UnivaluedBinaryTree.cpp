/*

*/
/*
A binary tree is univalued if every node in the tree has the same value.
Return true if and only if the given tree is univalued.


Example 1:
(pic)
Input: [1,1,1,1,1,null,1]
Output: true


Example 2:
(pic)
Input: [2,2,2,5,2]
Output: false
 

Note:
The number of nodes in the given tree will be in the range [1, 100].
Each node's value will be an integer in the range [0, 99].
*/

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return judge_unival(root, root->val);
    }

private:
    bool judge_unival(TreeNode* root, int value) {
        if (nullptr == root) {
            return true;
        }
        if (root->val != value) {
            return false;
        }
        auto left_res = judge_unival(root->left, value);
        auto right_res = judge_unival(root->right, value);
        return left_res && right_res;
    }
};