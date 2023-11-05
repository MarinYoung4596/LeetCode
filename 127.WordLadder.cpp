/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    127.WordLadder.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/22 21:53:25
*   @brief:

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every s_i for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: 0
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:
    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.

*****************************************************************/

class Node {
public:
    Node(int i, int s) : wid(i), step(s) {}
    Node(string w, int i, int s) : word(w), wid(i), step(s) {}

public:
    string word;
    int wid;
    int step;
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty()) {
            return 0;
        }
        const auto n = wordList.size();
        // 转换成图的邻接表表示
        vector<vector<int>> edges(n + 1, vector<int>());
        for (auto i = 0; i < n; ++i) {
            if (judge_connect(beginWord, wordList[i])) { // beginWord 的 id 是 n
                edges[n].push_back(i);
            }
            for (auto j = i + 1; j < n; ++j) {
                if (judge_connect(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        queue<Node> q;
        q.push(Node(beginWord, n, 1)); // 初始情况，step=1
        vector<bool> visited(n, false);
        while (!q.empty()) {
            auto cur_node = q.front();
            q.pop();

            if (cur_node.word == endWord) {
                return cur_node.step;
            }
            auto adjacent_ids = edges[cur_node.wid];
            for (auto aid : adjacent_ids) {
                if (visited[aid]) {
                    continue;
                }
                q.push(Node(wordList[aid], aid, cur_node.step + 1));
                visited[aid] = true;
            }
        }
        return 0;
    }

private:
    bool judge_connect(const string &word1, const string &word2) {
        auto diff_char_cnt = 0;
        for (auto i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                ++diff_char_cnt;
            }
        }
        return diff_char_cnt == 1;
    }
};