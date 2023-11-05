/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example:
You may serialize the following tree:
    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]"

Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

#include "util.h"

class TreeNode {
public:
    TreeNode(int v) : val(v) {}

public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encoder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        split(data, ',', vec);
        int index = 0;
        return decoder(vec, index);
    }

private:
    string encoder(TreeNode* root) {
        if (nullptr == root) {
            return "null";
        }
        return std::to_string(root->val) + \
               "," + encoder(root->left) + \
               "," + encoder(root->right);
    }

    TreeNode* decoder(const vector<string> &vec, int& index) {
        if (index >= vec.size()) {
            return nullptr;
        }
        if (vec[index] == "null") {
            return nullptr;
        }
        TreeNode* p = new TreeNode(std::stoi(vec[index]));
        p->left = decoder(vec, ++index);
        p->right = decoder(vec, ++index);
        return p;
    }

    void split(const string &str, char sep, vector<string> &vec) {
        auto begin = 0;
        auto end = str.find_first_of(sep, begin);
        while (end != string::npos) {
            vec.push_back(str.substr(begin, end - begin));

            begin = str.find_first_not_of(sep, end);
            end = str.find_first_of(sep, begin);
        }
        if (begin != end) {
            vec.push_back(str.substr(begin, str.size() - begin));
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec codec;
    string data1 = "1,2,null,null,3,4,null,null,5,null,null";
    auto tree1 = codec.deserialize(data1);
    auto ser1 = codec.serialize(tree1);
    std::cout << "input:\t" << data1 << '\n';
    std::cout << "output:\t" << ser1 << '\n';

    string data2 = "1,2,3,null,null,4,5";
    auto tree2 = codec.deserialize(data2);
    auto ser2 = codec.serialize(tree2);
    std::cout << "input:\t" << data2 << '\n';
    std::cout << "output:\t" << ser2 << '\n';
    return 0;
}
