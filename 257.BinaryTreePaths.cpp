/*
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
#include "TreeNode.h"
#include <vector>
#include <string>

// DFS Solution
std::vector<std::string> binaryTreePaths(TreeNode* root) {
	std::vector<std::string> res;
	std::string str;

	get_path(root, str, res);
	return res;
}

void get_path(TreeNode *root, std::string str, std::vector<std::string> &res) {
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
    if (root->left != nullptr) {
		get_path(root->left, str, res);
    }
	if (root->right != nullptr) {
		get_path(root->right, str, res);
    }
}