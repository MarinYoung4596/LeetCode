/*
117. Populating Next Right Pointers in Each Node II


Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (nullptr == root) {
            return;
        }
        if (nullptr == root->left && nullptr == root->right) {
            root->next = nullptr;
            return;
        }

        list<TreeLinkNode*> q, next;
        q.push_back(root);
        while (!q.empty()) {
            while (!q.empty()) {
                TreeLinkNode *tmp = q.front(); // current level
                q.pop_front();
                if (nullptr != tmp->left) {
                    next.push_back(tmp->left); // next level
                }
                if (nullptr != tmp->right) {
                    next.push_back(tmp->right);
                }
            }

            auto curr = next.begin();
            auto pre = curr++;
            while (curr != next.end()) {
                (*pre)->next = *curr;
                pre = curr++;
            }

            q.clear();
            std::swap(q, next);
        }
    }
};
