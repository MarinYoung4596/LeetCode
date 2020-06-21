/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (nullptr == root) {
            return std::vector<int>();
        }
        std::vector<int> vec;
        dfs(root, vec);

        std::unordered_map<int, int> vmap;
        for (const auto x : vec) {
            if (vmap.find(x) != vmap.end()) {
                ++vmap[x];
            } else {
                vmap[x] = 1;
            }
        }
        std::vector<std::pair<int, int>> modes;
        for (const auto &item : vmap) {
            modes.push_back({item.first, item.second});
        }
        std::sort(modes.begin(), modes.end(),
                  [&](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
                      return lhs.second > rhs.second;
                  });
        std::vector<int> result;
        result.push_back(modes[0].first);
        for (auto i = 1; i < modes.size() && modes[i].second == modes[0].second; ++i) {
            result.push_back(modes[i].first);
        }

        return result;
    }

private:
    void dfs(TreeNode* root, std::vector<int> &vec) {
        if (nullptr == root) {
            return;
        }
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
};