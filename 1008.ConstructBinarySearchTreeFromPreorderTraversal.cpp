/*
Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.


Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
(pic)


Constraints:
    1 <= preorder.length <= 100
    1 <= preorder[i] <= 10^8
    The values of preorder are distinct.
*/

// Runtime: 8 ms, faster than 33.28% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
// Memory Usage: 10.9 MB, less than 67.44% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size());
    }

private:
    TreeNode* construct(const std::vector<int> &preorder, int begin, int end) {
        if (begin >= end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[begin++]);
        auto idx = begin;
        while (idx < end && preorder[idx] < root->val) {
            ++idx;
        }
        root->left = construct(preorder, begin, idx);
        root->right = construct(preorder, idx, end);
        return root;
    }
};