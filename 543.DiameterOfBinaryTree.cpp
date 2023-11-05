/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/


// 判断最大路径是否要经过当前节点
// TODO:加备忘录,防止重复
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto left = diameterOfBinaryTree(root->left);  // 最大长度在左子树,不经过当前节点
        auto right = diameterOfBinaryTree(root->right); // 最大长度在右子树,不经过当前节点
        auto curr = dfs(root->left) + dfs(root->right); // 经过当前节点
        return std::max({left, right, curr});
    }

private:
    int dfs(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto left = dfs(root->left) + 1;
        auto right = dfs(root->right) + 1;
        return std::max(left, right);
    }
};


class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_depth(root);
        return max_diameter;
    }

    int max_depth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto left_depth = max_depth(root->left);
        auto right_depth = max_depth(root->right);
        auto cur_diameter = left_depth + right_depth;  // 当前的直径
        max_diameter = std::max(max_diameter, cur_diameter);
        return 1 + std::max(left_depth, right_depth);  // 当前节点为 root 的最大深度
    }

private:
    int max_diameter = 0;
};
