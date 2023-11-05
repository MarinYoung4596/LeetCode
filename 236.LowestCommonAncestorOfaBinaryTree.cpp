/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
between two nodes v and w as the lowest node in T that has both v and w as descendants
(where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is
LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the
LCA definition.
*/
#include "TreeNode.h"
#include <unordered_map>


// First Solution: Bottom-up
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        } else if (root == p || root == q) {
            return root;
        }

        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if (L != nullptr && R != nullptr) {
            return root;
        }
        return L != nullptr ? L : R;
    }
};


// Second Solution: 转换成求两个相交链表的 第一个相交节点
// To be continued...
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (nullptr == root) {
            return root;
        } else if (root == p || root == q) {
            return root;
        }

        std::unordered_map<TreeNode*, TreeNode*> parents;
        get_parents(root, parents);

        auto plen = get_node_to_root_len(p, parents);
        auto qlen = get_node_to_root_len(q, parents);

        if (plen > qlen) {
            for (auto i = 0; i < (plen - qlen); ++i) {
                p = parents[p];
            }
        } else if (qlen > plen) {
            for (auto i = 0; i < (qlen - plen); ++i) {
                q = parents[q];
            }
        }
        while (p != q) {
            p = parents[p];
            q = parents[q];
        }
        return p;
    }

private:
    int get_node_to_root_len(TreeNode* node,
                            const std::unordered_map<TreeNode*, TreeNode*> &parents) {
        auto len = 0;
        for (auto parent = node; parent != nullptr;) {
            auto iter = parents.find(parent);
            parent = iter != parents.end() ? iter->second : nullptr;
            ++len;
        }
        return len;
    }

    void get_parents(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*> &tmap) {
        if (nullptr == root) {
            return;
        }
        if (root->left != nullptr) {
            tmap[root->left] = root;
        }
        if (root->right != nullptr) {
            tmap[root->right] = root;
        }
        get_parents(root->left, tmap);
        get_parents(root->right, tmap);
    }
};