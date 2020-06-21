/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        // level order traversal
        return constructTree(nums, 0, nums.size()-1);
    }

private:
    TreeNode* constructTree(vector<int> &nums, size_t begin, size_t end)
    {
        if (begin > end) return nullptr;
        size_t mid = (begin+end+1)/2;       //begin + (end - begin + 1) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        if (mid - begin > 0)
            root->left = constructTree(nums, begin, mid - 1);
        else
            root->left = nullptr;
        
        if (end - begin > 0)
            root->right = constructTree(nums, mid + 1, end);
        else
           root->right = nullptr;
           
        return root;
    }
};