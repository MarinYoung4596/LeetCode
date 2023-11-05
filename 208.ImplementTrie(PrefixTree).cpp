/*
208. Implement Trie (Prefix Tree)

Implement a trie with insert, search, and starts_with methods.

Note: You may assume that all inputs are consist of lowercase letters a-z.

*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : ch(), exists(false) {
        for (auto i = 0; i < MaxBranchNums; ++i)
            child_node[i] = nullptr;
    }

    explicit TrieNode(char c) :ch(c), exists(false) {
        for (auto i = 0; i < MaxBranchNums; ++i) {
            child_node[i] = nullptr;
        }
    }

private:
    static const auto MaxBranchNums = 26;
    char ch;

public:
    TrieNode* child_node[MaxBranchNums];
    bool exists;
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(const string &word);

    // Returns if the word is in the trie.
    bool search(const string &word) const;

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool starts_with(const string &prefix) const;

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

void Trie::insert(const string &word) {
    if (word.empty()) {
        return;
    }
    auto p = root;
    for (auto it = word.begin(); it != word.end(); ++it) {
        int index = static_cast<int>(*it - 'a');
        if (p->child_node[index] == nullptr) {
            p->child_node[index] = new TrieNode(*it);
        }
        p = p->child_node[index];
    }
    p->exists = true;
}

bool Trie::search(const string &word) const {
    if (word.empty()) {
        return true;
    }
    auto p = root;
    for (auto it = word.begin(); it != word.end(); ++it) {
        int index = static_cast<int>(*it - 'a');
        if (p->child_node[index] == nullptr) {
            return false;
        }
        p = p->child_node[index];
    }
    return p->exists;
}

bool Trie::starts_with(const string &prefix) const {
    if (prefix.empty()) {
        return true;
    }
    auto p = root;
    for (auto it = prefix.begin(); it != prefix.end(); ++it) {
        int index = static_cast<int>(*it - 'a');
        if (p->child_node[index] == nullptr) {
            return false;
        }
        p = p->child_node[index];
    }
    return true;
}
