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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str;

        dfs(root, str, res);
        return res;
    }

private:
    void dfs(TreeNode *root, string str, vector<string> &res) {
        if (root == nullptr) {
            if (!str.empty()) {
                res.push_back(str);
            }
            return;
        }
        if (!str.empty()) {
            str += "->";
        }
        str += to_string(root->val);

        // leaf node
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(str);
            return;
        }
        dfs(root->left, str, res);
        dfs(root->right, str, res);
    }
};