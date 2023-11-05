/*
// same as LeetCode 114: Flatten binary tree to linked list

Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
 

Constraints:
    The number of nodes in the given tree will be between 1 and 100.
    Each node will have a unique integer value from 0 to 1000.
*/


class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (nullptr == root) {
            return root;
        }
        std::stack<TreeNode*> s;
        TreeNode new_root(-1);
        TreeNode* p = root;
        TreeNode* pre = &new_root;
        while (p != nullptr || !s.empty()) {
            if (p != nullptr) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();

                pre->right = p; // 
                pre = pre->right; //

                p->left = nullptr;
                p = p->right;
            }
        }
        return new_root.right;
    }
};