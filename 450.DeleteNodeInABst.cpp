/**
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:
root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].
    5
   / \
  2   6
   \   \
    4   7
*/


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (nullptr == root) {
            return root;
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else { // equal
            if (nullptr == root->left) {
                return root->right;
            } else if (nullptr == root->right) {
                return root->left;
            } else { // 左右子树均不为空
                // 找到左子树的最大节点 or 右子树的最小节点
                auto node = get_min_node(root->right);
                root->val = node->val; // 替代当前root，相当于删除
                root->right = deleteNode(root->right, node->val); // 删除右子树最小节点
            }
        }
        return root;
    }

private:
    TreeNode* get_min_node(TreeNode* root) {
        if (nullptr == root) {
            return root;
        }
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* get_max_node(TreeNode* root) {
        if (nullptr == root) {
            return root;
        }
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }
};