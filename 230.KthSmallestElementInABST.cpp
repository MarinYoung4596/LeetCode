/*
230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
    You may assume k is always valid, 1 = k = BST's total elements.

Follow up:
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:
    1.Try to utilize the property of a BST.
    2.What if you could modify the BST node's structure?
    3.The optimal runtime complexity is O(height of BST).

*/


// First Solution: iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // InOrder, non-recursive, kth element
        stack<TreeNode*> s;
        int count = 0;
        while(root != nullptr || !s.empty()) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                ++count;
                if (k == count) {
                    return root->val;
                }
                root = root->right;
            }
        }
        return INT_MIN;
    }
};

// Second Solution: recursive
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        return traverse_helper(root, 0, k);
    }

private:
    int traverse_helper(TreeNode* root, int cnt, int k) {
        if (nullptr == root) {
            return INT_MIN;
        }
        traverse_helper(root->left, cnt, k);
        cnt += 1;
        if (cnt == k) {
            return root->val;
        }
        traverse_helper(root->right, cnt, k);
    }
};
