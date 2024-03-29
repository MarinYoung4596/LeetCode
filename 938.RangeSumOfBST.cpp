/**
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.


Example 1:
    Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
    Output: 32


Example 2:
    Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
    Output: 23


Note:
    The number of nodes in the tree is at most 10000.
    The final answer is guaranteed to be less than 2^31.

*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> traverse;
        inorder_traverse(root, traverse);

        int result = 0;
        for (auto it = traverse.begin(); it != traverse.end() && *it <= R; ++it) {
            if (*it < L) {
                continue;
            }
            result += *it;
        }
        return result;
    }

private:
    void inorder_traverse(TreeNode* root, vector<int> &vec) {
        if (nullptr == root) {
            return;
        }
        inorder_traverse(root->left, vec);
        vec.push_back(root->val);
        inorder_traverse(root->right, vec);
    }
};
