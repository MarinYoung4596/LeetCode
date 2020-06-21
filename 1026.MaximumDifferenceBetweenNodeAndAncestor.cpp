/*
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)


Example 1:
(pic)
Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation:
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


Note:
    The number of nodes in the tree is between 2 and 5000.
    Each node will have value between 0 and 100000.
*/

// Runtime: 4 ms, faster than 98.33% of C++ online submissions for Maximum Difference Between Node and Ancestor.
// Memory Usage: 11.1 MB, less than 44.97% of C++ online submissions for Maximum Difference Between Node and Ancestor.
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, root->val, root->val, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int min_value, int max_value, int &result) {
        if (nullptr == root) {
            return;
        }
        result = std::max({result,
                          std::abs(min_value - root->val),
                          std::abs(max_value - root->val)
                          });
        dfs(root->left,
            std::min(min_value, root->val),
            std::max(max_value, root->val),
            result);
        dfs(root->right,
            std::min(min_value, root->val),
            std::max(max_value, root->val),
            result);
    }
};