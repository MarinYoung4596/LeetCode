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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return "[" + encoder(root) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<std::string> vec;
        split(data.substr(1, data.size() - 2), ',', vec);
        return decoder(vec);
    }

private:
    std::string encoder(TreeNode* root) {
        std::string result;
        if (nullptr == root) {
            return result;
        }
        result += std::to_string(root->val);
        if (nullptr != root->left) {
            result += ",";
            result += serialize(root->left);
        }
        if (nullptr != root->right) {
            if (nullptr == root->left) {
                result += ",null";
            }
            result += ",";
            result += serialize(root->right);
        }
        if (nullptr == root->left && nullptr == root->right) {
            result += "null,null";
        }
        return result;
    }

    TreeNode* decoder(const std::vector<std::string> &vec, int index = 0) {
        if (index < 0 || index >= vec.size()) {
            return nullptr;
        }
        if (vec[index] == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(std::stoi(vec[index]));
        root->left = decoder(vec, 2 * index + 1);
        root->right = decoder(vec, 2 * index + 2);
        return root;
    }

    void split(const std::string &str, char sep, std::vector<std::string> &vec) {
        auto begin = 0;
        auto end = str.find_first_of(sep, begin);
        while (end != std::string::npos) {
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
