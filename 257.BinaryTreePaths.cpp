/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:  ["1->2->5", "1->3"]
*/

#include "TreeNode.h"
#include <vector>
#include <string>

// DFS Solution
class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        std::string str;

        dfs(root, str, res);
        return res;
    }

private:
    void dfs(TreeNode *root, std::string str, std::vector<std::string> &res) {
        if (root == nullptr) {
            if (!str.empty()) {
                res.push_back(str);
            }
            return;
        }
        if (!str.empty()) {
            str += "->";
        }
        str += std::to_string(root->val);

        // leaf node
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(str);
            return;
        }
        dfs(root->left, str, res);
        dfs(root->right, str, res);
    }
};