#ifndef _TREENODE_H_
#define _TREENODE_H_

#include <vector>
#include <stack>
#include <queue>
#include <string>
#include "util.h"

// Definition for binary tree

struct TreeNode {
public:
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

// ----------------------------------------------------------------
// -------------- binary tree traversal operations ----------------
// preorder
void pre_order_traversal_iteration(TreeNode* root, std::vector<int> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode*> tree_stack;
    tree_stack.push(root);
    while (!tree_stack.empty()) {
        TreeNode* node = tree_stack.top();
        tree_stack.pop();
        vec.push_back(node->val);
        // 栈先入后出, 因此先push 右子树,后push左子树
        if (nullptr != node->right) {
            tree_stack.push(node->right);
        }
        if (nullptr != node->left) {
            tree_stack.push(node->left);
        }
    }
}


void pre_order_traversal_recursive(TreeNode* root, std::vector<int> &vec) {
    if (nullptr == root) {
        return;
    }
    vec.push_back(root->val);
    pre_order_traversal_recursive(root->left, vec);
    pre_order_traversal_recursive(root->right, vec);
}

// ----------------------------------------------------------------
// inorder
void in_order_traversal_iteration(TreeNode* root, std::vector<int> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode*> tree_stack;
    TreeNode* node = root;
    while (nullptr != node || !tree_stack.empty()) {
        if (nullptr != node) {
            tree_stack.push(node);
            node = node->left;
        } else {
            node = tree_stack.top();
            tree_stack.pop();
            vec.push_back(node->val);
            node = node->right;
        }
    }
}

void in_order_traversal_recursive(TreeNode* root, std::vector<int> &vec) {
    if (nullptr == root) {
        return;
    }
    in_order_traversal_recursive(root->left, vec);
    vec.push_back(root->val);
    in_order_traversal_recursive(root->right, vec);
}

// ----------------------------------------------------------------
// postorder
void post_order_traversal_iteration(TreeNode* root, std::vector<int> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode*> s1;
    std::stack<TreeNode*> s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node); //// <<<
        if (nullptr != node->left) {
            s1.push(node->left);
        }
        if (nullptr != node->right) {
            s1.push(node->right);
        }
    }
    while (!s2.empty()) {
        TreeNode* node = s2.top();
        s2.pop();
        vec.push_back(node->val);
    }
}

void post_order_traversal_recursive(TreeNode* root, std::vector<int> &vec) {
    if (nullptr == root) {
        return;
    }
    post_order_traversal_recursive(root->left, vec);
    post_order_traversal_recursive(root->right, vec);
    vec.push_back(root->val);
}

// ----------------------------------------------------------------
// level order

void level_order_traversal_iteration(
        TreeNode* root,
        std::vector<std::vector<int>> &vec) {
    if (nullptr == root) {
        return;
    }
    if (!vec.empty()) {
        vec.clear();
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto queue_size = q.size();
        std::vector<int> level;
        for (auto i = 0; i < queue_size; ++i) {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if (nullptr != node->left) {
                q.push(node->left);
            }
            if (nullptr != node->right) {
                q.push(node->right);
            }
        }
        vec.push_back(level);
    }
}

void level_order_traversal_recursive(
        TreeNode* root,
        std::size_t level,
        std::vector<std::vector<int>> &vec) {
    if (nullptr == root || level < 1) {
        return;
    }
    if (level > vec.size()) {
        vec.push_back(std::vector<int>());
    }
    vec[level - 1].push_back(root->val);
    level_order_traversal_recursive(root->left, level + 1, vec);
    level_order_traversal_recursive(root->right, level + 1, vec);
}

// ----------------------------------------------------------------
// --------------------- restore binary tree ----------------------

TreeNode* pre_and_in_build_helper(
        std::vector<int> &pre_order, int pre_begin, int pre_end,
        std::vector<int> &in_order, int in_begin, int in_end) {
    // VALID CHECK
    TreeNode* root = new TreeNode(pre_order[pre_begin]);
    // get left len and right len
    auto idx = in_begin;
    while (in_order[idx] != root->val) {
        ++idx;
    }
    auto left_len = idx - in_begin;
    auto right_len = in_end - idx;
    if (left_len > 0) {
        root->left = pre_and_in_build_helper(
                            pre_order, pre_begin + 1, pre_begin + left_len,
                            in_order, in_begin, in_begin + left_len - 1);
                            // in_begin + left_len - 1 = in_begin + (idx - in_begin) - 1 = idx - 1
    } else {
        root->left = nullptr;
    }

    if (right_len > 0) {
        root->right = pre_and_in_build_helper(
                            pre_order, pre_end - right_len + 1, pre_end,
                            in_order, in_end - right_len + 1, in_end);
                            // in_end - right_len + 1 = in_end - (in_end - idx) + 1 = idx + 1
    } else {
        root->right = nullptr;
    }
    return root;
}


TreeNode* construct_binary_tree_by_pre_and_in_order(
        std::vector<int> &pre_order,
        std::vector<int> &in_order) {
    if (pre_order.size() != in_order.size()) {
        return nullptr;
    }
    return pre_and_in_build_helper(
                        pre_order, 0, pre_order.size() - 1,
                        in_order, 0, in_order.size() - 1);
}

// ----------------------------------------------------------------


TreeNode* in_and_post_build_helper(
        std::vector<int> &in_order, int in_begin, int in_end,
        std::vector<int> &post_order, int post_begin, int post_end) {
    // VALID CHECK
    TreeNode* root = new TreeNode(post_order[post_end]);

    auto idx = in_begin;
    while (in_order[idx] != root->val) {
        ++idx;
    }
    auto left_len = idx - in_begin;
    auto right_len = in_end - idx;
    if (left_len > 0) {
        root->left = in_and_post_build_helper(
                        in_order, in_begin, in_begin + left_len - 1,
                        post_order, post_begin, post_begin + left_len - 1);
    } else {
        root->left = nullptr;
    }

    if (right_len > 0) {
        root->right = in_and_post_build_helper(
                        in_order, in_end - right_len + 1, in_end,
                        post_order, post_end - right_len, post_end - 1);
    }
    return root;
}


TreeNode* construct_binary_tree_by_in_and_post_order(
        std::vector<int> &in_order,
        std::vector<int> &post_order) {
    if (in_order.size() != post_order.size()) {
        return nullptr;
    }
    return in_and_post_build_helper(
                        in_order, 0, in_order.size() - 1,
                        post_order, 0, post_order.size() - 1);
}

// ----------------------------------------------------------------
// 获取树的深度
int get_tree_depth(TreeNode* root) {
    if (nullptr == root) {
        return 0;
    }
    auto left = 1 + get_tree_depth(root->left);
    auto right = 1 + get_tree_depth(root->right);
    return max(left, right);
}


// ----------------------------------------------------------------
// 判断是否为平衡二叉树
bool is_balanced_binary_tree(TreeNode* root) {
    if (nullptr == root) {
        return true;
    }
    auto left_depth = get_tree_depth(root->left);
    auto right_depth = get_tree_depth(root->right);
    if (abs(left_depth - right_depth) > 1) {
        return false;
    }
    return is_balanced_binary_tree(root->left) && is_balanced_binary_tree(root->right);
}

// ----------------------------------------------------------------
// ----------------- binary search tree operations ----------------
bool search_in_bst(TreeNode* root, const int &val) {
    if (nullptr == root) {
        return false;
    }
    if (root->val < val) {
        return search_in_bst(root->right, val);
    } else if (root->val > val) {
        return search_in_bst(root->left, val);
    } else {
        return true;
    }
}

TreeNode* insert_in_bst(TreeNode* root, const int& val) {
    if (nullptr == root) {
        return new TreeNode(val);
    } else if (root->val < val) {
        return insert_in_bst(root->right, val);
    } else if (root->val > val) {
        return insert_in_bst(root->left, val);
    } else {
        // 相等，do nothing
        return root;
    }
}

inline TreeNode* get_min_node(TreeNode* root) {
    // 仅适用于 bst
    if (nullptr == root) {
        return root;
    }
    while (nullptr != root->left) {
        root = root->left;
    }
    return root;
}

inline TreeNode* get_max_node(TreeNode* root) {
    // 仅适用于bst
    if (nullptr == root) {
        return root;
    }
    while (nullptr != root->right) {
        root = root->right;
    }
    return root;
}

TreeNode* delete_from_bst(TreeNode* root, const int &val) {
    if (nullptr == root) {
        return root;
    } else if (root->val < val) {
        root->right = delete_from_bst(root->right, val);
    } else if (root->val > val) {
        root->left = delete_from_bst(root->left, val);
    } else {
        if (nullptr == root->left) {
            return root->right;
        } else if (nullptr == root->right) {
            return root->left;
        } else {
            // 找到左子树最大节点，或右子树最小节点替代自己
            auto min_node = get_min_node(root->right);
            root->val = min_node->val;
            // 继续往下走，右子树最小节点已经放在root，因此该节点要被删除
            root->right = delete_from_bst(root->right, min_node->val);
        }
    }
    return root;
}

// ----------------------------------------------------------------
TreeNode* construct_binary_tree_by_vec(const std::vector<std::string> &vec, int &index) {
    if (index >= vec.size()) {
        return nullptr;
    }
    if (vec[index] == "null") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(std::stoi(vec[index]));
    root->left = construct_binary_tree_by_vec(vec, ++index);
    root->right = construct_binary_tree_by_vec(vec, ++index);
    return root;
}

TreeNode* deserialize_binary_tree(const std::string &str) {
    std::vector<std::string> vec;
    split(str, ',', vec);
    auto index = 0;
    return construct_binary_tree_by_vec(vec, index);
}

std::string serialize_binary_tree(TreeNode* root) {
    if (nullptr == root) {
        return "null";
    }
    return std::to_string(root->val) + "," + \
           serialize_binary_tree(root->left) + "," + \
           serialize_binary_tree(root->right);
}


#endif
