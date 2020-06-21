#ifndef _TREENODE_H_
#define _TREENODE_H_

#include <vector>
#include <stack>
#include <queue>
#include <string>
#include "util.h"

//Definition for binary tree
template <typename T>
struct TreeNode {
public:
    explicit TreeNode(T x) : value(x), left(nullptr), right(nullptr) {}

public:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

// ----------------------------------------------------------------
// -------------- binary tree traversal operations ----------------
// preorder
template <typename T>
void pre_order_traversal_iteration(TreeNode<T>* root, std::vector<T> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode<T>*> tree_stack;
    tree_stack.push(root);
    while (!tree_stack.empty()) {
        TreeNode<T>* node = tree_stack.top();
        tree_stack.pop();
        vec.push_back(node->value);
        // 栈先入后出, 因此先push 右子树,后push左子树
        if (nullptr != node->right) {
            tree_stack.push(node->right);
        }
        if (nullptr != node->left) {
            tree_stack.push(node->left);
        }
    }
}

template <typename T>
void pre_order_traversal_recursive(TreeNode<T>* root, std::vector<T> &vec) {
    if (nullptr == root) {
        return;
    }
    vec.push_back(root->value);
    pre_order_traversal_recursive(root->left, vec);
    pre_order_traversal_recursive(root->right, vec);
}

// ----------------------------------------------------------------
// inorder
template <typename T>
void in_order_traversal_iteration(TreeNode<T>* root, std::vector<T> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode<T>*> tree_stack;
    TreeNode<T>* node = root;
    while (nullptr != node || !tree_stack.empty()) {
        if (nullptr != node) {
            tree_stack.push(node);
            node = node->left;
        } else {
            node = tree_stack.top();
            tree_stack.pop();
            vec.push_back(node->value);
            node = node->right;
        }
    }
}

template <typename T>
void in_order_traversal_recursive(TreeNode<T>* root, std::vector<T> &vec) {
    if (nullptr == root) {
        return;
    }
    in_order_traversal_recursive(root->left, vec);
    vec.push_back(root->value);
    in_order_traversal_recursive(root->right, vec);
}

// ----------------------------------------------------------------
// postorder
template <typename T>
void post_order_traversal_iteration(TreeNode<T>* root, std::vector<T> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode<T>*> s1;
    std::stack<TreeNode<T>*> s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode<T>* node = s1.top();
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
        TreeNode<T>* node = s2.top();
        s2.pop();
        vec.push_back(node->value);
    }
}

template <typename T>
void post_order_traversal_recursive(TreeNode<T>* root, std::vector<T> &vec) {
    if (nullptr == root) {
        return;
    }
    post_order_traversal_recursive(root->left, vec);
    post_order_traversal_recursive(root->right, vec);
    vec.push_back(root->value);
}

// ----------------------------------------------------------------
// level order
template <typename T>
void level_order_traversal_iteration(
        TreeNode<T>* root,
        std::vector<std::vector<T>> &vec) {
    if (nullptr == root) {
        return;
    }
    std::queue<TreeNode<T> *> curr_queue;
    std::queue<TreeNode<T> *> next_queue;
    std::vector<T> level;

    curr_queue.push(root);
    while (!curr_queue.empty()) {
        while (!curr_queue.empty()) {
            TreeNode<T>* node = curr_queue.front();
            curr_queue.pop();
            level.push_back(node->value);
            if (nullptr != node->left) {
                next_queue.push(node->left);
            }
            if (nullptr != node->right) {
                next_queue.push(node->right);
            }
        }
        vec.push_back(level);
        level.clear();
        swap(curr_queue, next_queue); // TODO
    }
}

template <typename T>
void level_order_traversal_recursive(
        TreeNode<T>* root,
        std::size_t level,
        std::vector<std::vector<T>> &vec) {
    if (nullptr == root || level < 1) {
        return;
    }
    if (level > vec.size()) {
        vec.push_back(std::vector<T>());
    }
    vec[level - 1].push_back(root->value);
    level_order_traversal_recursive(root->left, level + 1, vec);
    level_order_traversal_recursive(root->right, level + 1, vec);
}

// ----------------------------------------------------------------
// zigzag level order
template <typename T>
void zigzag_level_order_traversal_iteration(
        TreeNode<T>* root,
        std::vector<std::vector<T>> &vec) {
    if (nullptr == root) {
        return;
    }
    std::stack<TreeNode<T>*> s1;
    std::stack<TreeNode<T>*> s2;
    // todo
}

// ----------------------------------------------------------------
// --------------------- restore binary tree ----------------------
template <typename T>
TreeNode<T>* pre_and_in_build_helper(
        std::vector<T> &pre_order, int pre_begin, int pre_end,
        std::vector<T> &in_order, int in_begin, int in_end) {
    // VALID CHECK
    TreeNode<T>* root = new TreeNode<T>(pre_order[pre_begin]);
    // get left len and right len
    auto idx = in_begin;
    while (in_order[idx] != root->value) {
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

template <typename T>
TreeNode<T>* construct_binary_tree_by_pre_and_in_order(
        std::vector<T> &pre_order,
        std::vector<T> &in_order) {
    if (pre_order.size() != in_order.size()) {
        return nullptr;
    }
    return pre_and_in_build_helper(
                        pre_order, 0, pre_order.size() - 1,
                        in_order, 0, in_order.size() - 1);
}

// ----------------------------------------------------------------

template <typename T>
TreeNode<T>* in_and_post_build_helper(
        std::vector<T> &in_order, int in_begin, int in_end,
        std::vector<T> &post_order, int post_begin, int post_end) {
    // VALID CHECK
    TreeNode<T>* root = new TreeNode<T>(post_order[post_end]);

    auto idx = in_begin;
    while (in_order[idx] != root->value) {
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

template <typename T>
TreeNode<T>* construct_binary_tree_by_in_and_post_order(
        std::vector<T> &in_order,
        std::vector<T> &post_order) {
    if (in_order.size() != post_order.size()) {
        return nullptr;
    }
    return in_and_post_build_helper(
                        in_order, 0, in_order.size() - 1,
                        post_order, 0, post_order.size() - 1);
}

// ----------------------------------------------------------------
// 获取树的深度
template <typename T>
int get_depth_recursive(TreeNode<T>* root) {
    if (nullptr == root) {
        return 0;
    }
    auto left = 1 + get_depth(root->left);
    auto right = 1 + get_depth(root->right);
    return max(left, right);
}

template <typename T>
int get_depth_iteration(TreeNode<T>* root) {

}

// ----------------------------------------------------------------
// 判断是否为平衡二叉树
template <typename T>
bool is_balanced_binary_tree(TreeNode<T>* root) {
    if (nullptr == root) {
        return true;
    }
    auto left_depth = get_depth(root->left);
    auto right_depth = get_depth(root->right);
    if (abs(left_depth - right_depth) > 1) {
        return false;
    }
    return is_balanced_binary_tree(root->left) && is_balanced_binary_tree(root->right);
}

// ----------------------------------------------------------------
// ----------------- binary search tree operations ----------------
template <typename T>
bool search_in_bst(TreeNode<T>* root, const T &value) {
    if (nullptr == root) {
        return false;
    }
    if (root->value < value) {
        return search_in_bst(root->right, value);
    } else if (root->value > value) {
        return search_in_bst(root->left, value);
    } else {
        return true;
    }
}

template <typename T>
TreeNode<T>* insert_in_bst(TreeNode<T>* root, const T& value) {
    if (nullptr == root) {
        return new TreeNode<T>(value);
    } else if (root->value < value) {
        return insert_in_bst(root->right, value);
    } else if (root->value > value) {
        return insert_in_bst(root->left, value);
    } else {
        // 相等，do nothing
        return root;
    }
}

template <typename T>
inline TreeNode<T>* get_min_node(TreeNode<T>* root) {
    if (nullptr == root) {
        return root;
    }
    while (nullptr != root->left) {
        root = root->left;
    }
    return root;
}

template <typename T>
inline TreeNode<T>* get_max_node(TreeNode<T>* root) {
    if (nullptr == root) {
        return root;
    }
    while (nullptr != root->right) {
        root = root->right;
    }
    return root;
}

template <typename T>
TreeNode<T>* delete_from_bst(TreeNode<T>* root, const T &value) {
    if (nullptr == root) {
        return root;
    } else if (root->value < value) {
        root->right = delete_from_bst(root->right, value);
    } else if (root->value > value) {
        root->left = delete_from_bst(root->left, value);
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
TreeNode<int>* construct_binary_tree_by_vec(const std::vector<std::string> &vec, int index = 0) {
    if (index < 0 || index > vec.size()) {
        return nullptr;
    }
    if (vec[index] == "null") {
        return nullptr;
    }
    TreeNode<int>* root = new TreeNode<int>(std::stoi(vec[index]));
    root->left = construct_binary_tree_by_vec(vec, 2 * index + 1);
    root->right = construct_binary_tree_by_vec(vec, 2 * index + 2);
    return root;
}

TreeNode<int>* deserialize_binary_tree(const std::string &str) {
    std::vector<std::string> vec;
    split(str.substr(1, str.size() - 2), ',', vec);
    return construct_binary_tree_by_vec(vec);
}

std::string binary_tree_to_str(TreeNode<int>* root) {
    if (nullptr == root) {
        return std::string();
    }
    std::string result;
    result += std::to_string(root->value);
    if (nullptr != root->left) {
        result += ",";
        result += binary_tree_to_str(root->left);
    }
    if (nullptr != root->right) {
        if (nullptr == root->left) {
            result += ",";
            result += "null";
        }
        result += ",";
        result += binary_tree_to_str(root->right);
    }
    return result;
}

std::string serialize_binary_tree(TreeNode<int>* root) {
    return "[" + binary_tree_to_str(root) + "]";
}


#endif
