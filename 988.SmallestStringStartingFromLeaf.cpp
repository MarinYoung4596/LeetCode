/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    988.SmallestStringStartingFromLeaf.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/22 01:15:11
*   @brief:

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller. For example, "ab" is lexicographically smaller than "aba".

A leaf of a node is a node that has no children.



Example 1:
    Input: root = [0,1,2,3,4,3,4]
    Output: "dba"

Example 2:
    Input: root = [25,1,3,1,3,0,2]
    Output: "adz"

Example 3:
    Input: root = [2,2,1,null,1,0,null,0]
    Output: "abc"


Constraints:
    The number of nodes in the tree is in the range [1, 8500].
    0 <= Node.val <= 25

*****************************************************************/

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        int min_value = INT_MAX;
        unordered_map<TreeNode*, TreeNode*> node_map;
        get_parent_node_map(root, node_map, min_value);

        string result = "";
        traverse(root, node_map, min_value, result);
        return result;
    }

private:
    void get_parent_node_map(TreeNode* root,
                             unordered_map<TreeNode*, TreeNode*> &node_map,
                             int &min_value) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            node_map[root->left] = root;
            get_parent_node_map(root->left, node_map, min_value);
        }
        if (root->right != nullptr) {
            node_map[root->right] = root;
            get_parent_node_map(root->right, node_map, min_value);
        }
        if (root->left == nullptr && root->right == nullptr) {
            min_value = std::min(min_value, root->val);
        }
    }

    string get_leaf_to_root_str(TreeNode* leaf,
                                unordered_map<TreeNode*, TreeNode*> &node_map) {
        char v[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'
                    };
        string result;
        result += v[leaf->val];

        auto it = node_map.find(leaf);
        while (it != node_map.end()) {
            auto parent = it->second;
            result += v[parent->val];
            it = node_map.find(parent);
        }
        return result;
    }

    void traverse(TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*> &node_map,
                 int min_value,
                 string &result) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr && root->val == min_value) {
            auto tmp = get_leaf_to_root_str(root, node_map);
            if (result.empty() || compare(tmp, result) > 0) {
                result = tmp;
            }
        }
        traverse(root->left, node_map, min_value, result);
        traverse(root->right, node_map, min_value, result);
    }

    int compare(const string &s1, const string &s2) {
        auto min_len = std::min(s1.size(), s2.size());
        for (auto i = 0; i < min_len; ++i) {
            if (s1[i] != s2[i]) {
                return s1[i] < s2[i] ? 1 : -1;
            }
        }
        return s1.size() == min_len ? 1 : -1;
    }
};