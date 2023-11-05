/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.


Example:
    (pic)
    BSTIterator iterator = new BSTIterator(root);
    iterator.next();    // return 3
    iterator.next();    // return 7
    iterator.hasNext(); // return true
    iterator.next();    // return 9
    iterator.hasNext(); // return true
    iterator.next();    // return 15
    iterator.hasNext(); // return true
    iterator.next();    // return 20
    iterator.hasNext(); // return false


Note:
    next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
    You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/


class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        iter = vec.begin();
    }

    /** @return the next smallest number */
    int next() {
        return *(iter++);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iter != vec.end();
    }

private:
    void inorder(TreeNode* root) {
        if (nullptr == root) {
            return;
        }
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }

private:
    std::vector<int> vec;
    std::vector<int>::iterator iter;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */