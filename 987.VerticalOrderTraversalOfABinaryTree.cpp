/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    987.VerticalOrderTraversalOfABinaryTree.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/06 22:58:58
*   @brief:

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.


Example 1:
    (pic)
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation:
    Column -1: Only node 9 is in this column.
    Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
    Column 1: Only node 20 is in this column.
    Column 2: Only node 7 is in this column.

Example 2:
(pic)
    Input: root = [1,2,3,4,5,6,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation:
        Column -2: Only node 4 is in this column.
        Column -1: Only node 2 is in this column.
        Column 0: Nodes 1, 5, and 6 are in this column.
                1 is at the top, so it comes first.
                5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
        Column 1: Only node 3 is in this column.
        Column 2: Only node 7 is in this column.

Example 3:
    (pic)
    Input: root = [1,2,3,4,6,5,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation:
        This case is the exact same as example 2, but with nodes 5 and 6 swapped.
        Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.


Constraints:
    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 1000

*****************************************************************/


class Node {
public:
    Node(TreeNode* p, int r, int c) : p_node(p), row_index(r), col_index(c) {}

    bool operator<(const Node& rhs) {
        if (this->col_index != rhs.col_index) {
            return this->col_index < rhs.col_index;
        } else if (this->row_index != rhs.row_index) {
            return this->row_index < rhs.row_index;
        } else {
            return this->p_node->val < rhs.p_node->val;
        }
    }

public:
    TreeNode* p_node;
    int row_index;
    int col_index;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (nullptr == root) {
            return result;
        }
        vector<Node> vec;
        queue<Node> q;
        q.push(Node(root, 0, 0));
        while (!q.empty()) {
            auto queue_len = q.size();
            for (auto i = 0; i < queue_len; ++i) {
                auto node = q.front();
                q.pop();
                vec.push_back(node);
                auto p_node = node.p_node;
                if (p_node->left != nullptr) {
                    q.push(Node(p_node->left, node.row_index + 1, node.col_index - 1));
                }
                if (p_node->right != nullptr) {
                    q.push(Node(p_node->right, node.row_index + 1, node.col_index + 1));
                }
            }
        }
        std::sort(vec.begin(), vec.end());

        vector<int> subres;
        int pre_col_index;
        for (auto i = 0; i < vec.size(); ++i) {
            auto &cur = vec[i];
            if (i > 0 && pre_col_index != cur.col_index) {
                result.push_back(subres);
                subres.clear();
            }
            pre_col_index = cur.col_index;
            subres.push_back(cur.p_node->val);
        }
        if (!subres.empty()) {
            result.push_back(subres);
        }
        return result;
    }
};