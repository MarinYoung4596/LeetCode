/*
We are given a binary tree (with root node root), a target node, and an integer value K.
Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.


Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
    Output: [7,4,1]
    Explanation:
        The nodes that are a distance 2 from the target node (with value 5)
        have values 7, 4, and 1.

    Note that the inputs "root" and "target" are actually TreeNodes.
    The descriptions of the inputs above are just serializations of these objects.


Note:
    The given tree is non-empty.
    Each node in the tree has unique values 0 <= node.val <= 500.
    The target node is a node in the tree.
    0 <= K <= 1000.
*/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parents;
        get_parents(root, parents);

        unordered_set<TreeNode*> visited;
        vector<int> result;
        dfs(target, K, parents, visited, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int k,
             unordered_map<TreeNode*, TreeNode*> &parents,
             unordered_set<TreeNode*> &visited,
             vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        if (visited.find(root) != visited.end()) { /// 注意
            return;
        }
        if (k == 0) {
            result.push_back(root->val);
            return;
        }
        visited.insert(root);
        // 往下走 k 步
        dfs(root->left, k - 1, parents, visited, result);
        dfs(root->right, k - 1, parents, visited, result);
        // 往上走 k 步
        auto parent = parents[root];
        dfs(parent, k - 1, parents, visited, result);
    }

    void get_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            parents[root->left] = root;
        }
        if (root->right != nullptr) {
            parents[root->right] = root;
        }
        get_parents(root->left, parents);
        get_parents(root->right, parents);
    }
};
