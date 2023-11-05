/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

(pic)

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.


Constraints:
    Both of the given trees will have between 1 and 200 nodes.
    Both of the given trees will have values between 0 and 200
*/


class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> seq1;
        get_leaf_sequence(root1, seq1);
        std::vector<int> seq2;
        get_leaf_sequence(root2, seq2);
        if (seq1.size() != seq2.size()) {
            return false;
        }
        for (auto i = 0; i < seq1.size(); ++i) {
            if (seq1[i] != seq2[i]) {
                return false;
            }
        }
        return true;
    }
    
private:
    void get_leaf_sequence(TreeNode* root, std::vector<int> &seq) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            seq.push_back(root->val);
            return;
        }
        get_leaf_sequence(root->left, seq);
        get_leaf_sequence(root->right, seq);
    }
};
