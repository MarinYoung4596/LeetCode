/*
Design a data structure that supports the following two operations:
    void addWord(word)
    bool search(word)
        search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:
    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
    search(".ad") -> true
    search("b..") -> true

Note:
    You may assume that all words are consist of lowercase letters a-z.

click to show hint.
    You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : ch(), exists(false) {
        for (auto i = 0; i < MaxBranchNums; ++i) {
            childNode[i] = nullptr;
        }
    }

    explicit TrieNode(char c) : ch(c), exists(false) {
        for (auto i = 0; i < MaxBranchNums; ++i) {
            childNode[i] = nullptr;
        }
    }

public:
    static const auto MaxBranchNums = 26; // 纯lowercase，如果有大写或数字会更大。
    TrieNode* childNode[MaxBranchNums];//用index来表示相应的字母。
    // 以下两项完全非必需，可以去掉
    char ch;
    int freq;
    bool exists;
};



class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(const string &word);

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(const string &word);

private:
    TrieNode *root;
    bool search(TrieNode *node, const string &word, int searchIndex);
};

void WordDictionary::addWord(const string &word) {
    if (word.empty()) {
        return;
    }
    auto p = root;
    for (auto i = 0; i < word.size(); ++i) {
        auto index = static_cast<int>(word[i] - 'a');
        if (nullptr == p->childNode[index]) {
            p->childNode[index] = new TrieNode(word[i]);
        }
        p = p->childNode[index];
    }
    p->exists = true;
}

bool WordDictionary::search(const string &word) {
    return search(root, word, 0);
}

// backtracking
bool WordDictionary::search(TrieNode *node, const string &word, int i) {
    if (i == word.size()) return node->exists;
    if (node == nullptr) return false;

    auto p = node;
    auto index = static_cast<int>(word[i] - 'a');
    if (word[i] != '.') {
        if (nullptr == p->childNode[index]) return false;
        return search(p->childNode[index], word, i + 1);
    }
    for (auto j = 0; j < p->MaxBranchNums; ++j) {
        if (nullptr == p->childNode[j]) continue;
        return search(p->childNode[j], word, i + 1);
    }
    return false;
}
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
