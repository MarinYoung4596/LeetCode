/*
208. Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods. 

Note:
 You may assume that all inputs are consist of lowercase letters a-z. 

*/

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() : ch(), exists(false)
	{
		for (auto i = 0; i < MaxBranchNums; ++i)
			childNode[i] = nullptr;
	}

	explicit TrieNode(char c) :ch(c), exists(false)
	{
		for (auto i = 0; i < MaxBranchNums; ++i)
			childNode[i] = nullptr;
	}

private:
	static const auto MaxBranchNums = 26;
	char ch;

public:
	TrieNode* childNode[MaxBranchNums];
	// int freq;
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
	bool startsWith(const string &prefix) const;

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

void Trie::insert(const string &word)
{
	if (word.empty()) return;
	auto p = root;
	for (auto it = word.begin(); it != word.end(); ++it)
	{
		int index = static_cast<int>(*it - 'a');
		if (p->childNode[index] == nullptr)
		{
			p->childNode[index] = new TrieNode(*it);
		}
		p = p->childNode[index];
	}
	p->exists = true;
}

bool Trie::search(const string &word) const
{
	if (word.empty()) return true;
	auto p = root;
	for (auto it = word.begin(); it != word.end(); ++it)
	{
		int index = static_cast<int>(*it - 'a');
		if (p->childNode[index] == nullptr) return false;

		p = p->childNode[index];
	}
    return p->exists;
}

bool Trie::startsWith(const string &prefix) const
{
	if (prefix.empty()) return true;
	auto p = root;
	for (auto it = prefix.begin(); it != prefix.end(); ++it)
	{
		int index = static_cast<int>(*it - 'a');
		if (p->childNode[index] == nullptr) return false;

		p = p->childNode[index];
	}
	return true;
}
