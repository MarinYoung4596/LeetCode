/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/


Given an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).


Follow up:
    Recursive solution is trivial, could you do it iteratively?


Example 1:
    Input: root = [1,null,3,2,4,null,5,6]
    Output: [1,3,5,6,2,4]


Example 2:
    Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]


Constraints:
    The height of the n-ary tree is less than or equal to 1000
    The total number of nodes is between [0, 10^4]
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorder_helper(root, result);
        return result;
    }

private:
    void preorder_helper(Node* root, vector<int> &vec) {
        if (nullptr == root) {
            return;
        }
        vec.push_back(root->val);
        for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            preorder_helper(*it, vec);
        }
    }
};