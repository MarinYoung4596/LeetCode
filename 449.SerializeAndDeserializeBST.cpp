/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    449.SerializeAndDeserializeBST.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/11 13:12:09
*   @brief:

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.


Example 1:
    Input: root = [2,1,3]
    Output: [2,1,3]

Example 2:
    Input: root = []
    Output: []


Constraints:
    The number of nodes in the tree is in the range [0, 10^4].
    0 <= Node.val <= 10^4
    The input tree is guaranteed to be a binary search tree.

*****************************************************************/


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        encode(root, result);

        if (!result.empty() && result[result.size() - 1] == ',') {
            result = result.substr(0, result.size() - 1);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;

        TreeNode* root = nullptr;
        while (getline(ss, item, ',')) {
            root = insert(root, stoi(item));
        }
        return root;
    }

private:
    void encode(TreeNode* root, string &result) {
        if (nullptr == root) {
            return;
        }
        result += to_string(root->val);
        result += ",";
        encode(root->left, result);
        encode(root->right, result);
    }

    TreeNode* insert(TreeNode* root, int value) {
        if (nullptr == root) {
            root = new TreeNode(value);
            return root;
        }
        if (root->val >= value) {
            root->left = insert(root->left, value);
        } else if (root->val < value) {
            root->right = insert(root->right, value);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
