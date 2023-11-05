/*
Given two binary search trees root1 and root2.
Return a list containing all the integers from both trees sorted in ascending order.


Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]


Example 2:
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]


Example 3:
Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]


Example 4:
Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]


Example 5:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


Constraints:
    Each tree has at most 5000 nodes.
    Each node's value is between [-10^5, 10^5].
*/


// Runtime: 224 ms, faster than 87.06% of C++ online submissions for All Elements in Two Binary Search Trees.
// Memory Usage: 85.3 MB, less than 39.51% of C++ online submissions for All Elements in Two Binary Search Trees.
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec1;
        traverse(root1, vec1);
        std::vector<int> vec2;
        traverse(root2, vec2);
        return merge(vec1, vec2);
    }

private:
    void traverse(TreeNode* root, std::vector<int> &vec) {
        if (nullptr == root) {
            return;
        }
        traverse(root->left, vec);
        vec.push_back(root->val);
        traverse(root->right, vec);
    }

    std::vector<int> merge(const std::vector<int> &vec1, const std::vector<int> &vec2) {
        if (vec1.empty()) {
            return vec2;
        }
        if (vec2.empty()) {
            return vec1;
        }
        std::vector<int> vec(vec1.size() + vec2.size(), 0);
        auto i = 0;
        auto j = 0;
        auto k = 0;
        while (i < vec1.size() && j < vec2.size()) {
            if (vec1[i] < vec2[j]) {
                vec[k++] = vec1[i++];
            } else {
                vec[k++] = vec2[j++];
            }
        }
        while (i < vec1.size()) {
            vec[k++] = vec1[i++];
        }
        while (j < vec2.size()) {
            vec[k++] = vec2[j++];
        }
        return vec;
    }
};