/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

    1.  5 -> 3
    2.  5 -> 2 -> 1
    3. -3 -> 11
*/


// First solution: DFS
// TODO：这里可以用一个 visited 数组，把已经遍历到答案的节点缓存，降低开销
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (nullptr == root) {
            return 0;
        }
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int dfs(TreeNode* root, int sum) {
        if (nullptr == root) {
            return 0;
        }
        int flag = (sum == root->val ? 1 : 0); // 相当于先序遍历
        return flag + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
};


// Second Solution: https://www.cnblogs.com/grandyang/p/6007336.html
class Solution2 {
public:
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        std::vector<TreeNode* > preorder;
        backtrack(root, sum, 0, preorder, result);
        return result;
    }

private:
    void backtrack(TreeNode* root,
                    int sum,
                    int curr_sum,
                    std::vector<TreeNode*> &preorder,
                    int &result) {
        if (nullptr == root) {
            return;
        }
        curr_sum += root->val;
        if (curr_sum == sum) {
            ++result;
        }
        auto tmp = curr_sum;
        for (auto it = preorder.begin(); it != preorder.end(); ++it) {
            tmp -= (*it)->val;
            if (tmp == sum) {
                ++result;
            }
        }
        preorder.push_back(root);
        backtrack(root->left, sum, curr_sum, preorder, result);
        backtrack(root->right, sum, curr_sum, preorder, result);
        preorder.pop_back();
    }
};
