/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]
   1
  /
 3
  \
   2

Output: [3,1,null,null,2]
   3
  /
 1
  \
   2


Example 2:
Input: [3,1,4,null,null,2]
  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]
  2
 / \
1   4
   /
  3


Follow up:
    A solution using O(n) space is pretty straight forward.
    Could you devise a constant space solution?
*/

// First Solution : Space Complexity: O(1)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // 中序遍历
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (nullptr != p || !s.empty()) {
            if (nullptr != p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();

                // 中序遍历，必然 pre->val < p->val, 否则肯定有问题
                if (nullptr != pre && pre->val > p->val) {
                    if (nullptr == first) {
                        first = pre;
                    }
                    second = p; // 保存异常值, 后续循环可能还会更新
                }
                pre = p;
                p = p->right;
            }
        }
        swap(first->val, second->val);
    }
};


// Second Solution : Space Complexity: O(N)
class Solution2 {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> values;
        inorder(root, list, values);
        sort(values.begin(), values.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = values[i];
        }
    }

private:
    void inorder(TreeNode* root, vector<TreeNode*> &list, vector<int> &values) {
        if (nullptr == root) {
            return;
        }
        inorder(root->left, list, values);

        list.push_back(root);
        values.push_back(root->val);

        inorder(root->right, list, values);
    }
};