/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    652.FindDuplicateSubtrees.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/06 23:15:49
*   @brief:
*
*****************************************************************/


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode* > result;
        unordered_map<string, int> str_map;
        dfs(root, result, str_map);
        return result;
    }

private:
    string dfs(TreeNode* root,
               vector<TreeNode*> &result,
               unordered_map<string, int> &str_map) {
        if (nullptr == root) {
            return "null";
        }
        auto str = std::to_string(root->val) + "," + \
                   dfs(root->left, result, str_map) + "," + \
                   dfs(root->right, result, str_map);  // 以当前节点为root的先序遍历结果
        auto iter = str_map.find(str);
        if (iter == str_map.end()) {
            str_map[str] = 1;
        } else {
            if (iter->second == 1) {
                result.push_back(root);  // 第一次才push
            }
            str_map[str] ++;
        }
        return str;
    }
};