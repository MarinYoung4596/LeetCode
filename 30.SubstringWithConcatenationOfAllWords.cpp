/*****************************************************************
*   Copyright (C) 2022 All rights reserved.
*
*   @file:    30.SubstringWithConcatenationOfAllWords.cpp
*   @author:  marinyoung@163.com
*   @date:    2022/12/31 17:36:22
*   @brief:

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.



Example 1:
    Input: s = "barfoothefoobarman", words = ["foo","bar"]
    Output: [0,9]
    Explanation:
          Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
        The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
        The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
        The output order does not matter. Returning [9,0] is fine too.

Example 2:
    Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
    Output: []
    Explanation:
        Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
        There is no substring of length 16 is s that is equal to the concatenation of any permutation of words.
        We return an empty array.

Example 3:
    Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
    Output: [6,9,12]
    Explanation:
        Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
        The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
        The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
        The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.


Constraints:
    1 <= s.length <= 10^4
    1 <= words.length <= 5000
    1 <= words[i].length <= 30
    s and words[i] consist of lowercase English letters.


*****************************************************************/

#include "util.h"

// First Solution: backtrack + hardmap, TLE
class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) {
            return res;
        }
        auto word_len = words[0].size();
        if (s.size() < word_len * words.size()) {
            return res;
        }
        vector<string> permuations;
        get_all_permuation(words, permuations);

        // 去重
        sort(permuations.begin(), permuations.end());
        permuations.erase(unique(permuations.begin(), permuations.end()), permuations.end());
        //
        for (const auto &item : permuations) {
            auto pos = s.find(item);
            while (pos != string::npos) {  // 存在多个 pos
                res.push_back(pos);
                pos = s.find(item, pos + 1);
            }
        }
        return res;
    }

private:
    void get_all_permuation(const vector<string> &words,
                            vector<string> &permuations) {
        vector<string> sub_res;
        unordered_set<int> sub_res_index;
        get_permuation_helper(words, permuations, sub_res, sub_res_index);
    }

    void get_permuation_helper(const vector<string> &words,
                               vector<string> &all_res,
                               vector<string> &sub_res,
                               unordered_set<int> &sub_res_index) {
        if (sub_res.size() == words.size()) {
            all_res.push_back(vec_to_str(sub_res));
            return;
        }

        for (auto i = 0; i < words.size(); ++i) {
            auto& item = words[i];
            if (sub_res_index.count(i) > 0) {
                continue;
            }

            sub_res.push_back(item);
            sub_res_index.insert(i);
            get_permuation_helper(words, all_res, sub_res, sub_res_index);
            sub_res.pop_back();
            sub_res_index.erase(i);
        }
    }

    string vec_to_str(const vector<string> &vec) {
        string res;
        for (const auto &item : vec) {
            res += item;
        }
        return res;
    }
};

// second solution: slidding window + hashmap
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) {
            return res;
        }
        auto word_len = words[0].size();
        auto sum_len = word_len * words.size();
        if (s.size() < sum_len) {
            return res;
        }
        unordered_map<string, int> word_map;
        get_word_cnt_map(words, word_map);

        // slidding window
        for (auto i = 0; i <= s.size() - sum_len; ++i) {
            // get word map in window [i, i + sum_len]
            unordered_map<string, int> tmp_word_map;
            for (auto c = 0; c < words.size(); ++c) {
                auto cur_word = s.substr(i + c * word_len, word_len);
                // printf("i=%d, c=%d, word_begin=%d, word=%s\n", i, c, i + c*word_len, cur_word.c_str());
                if (tmp_word_map.count(cur_word) > 0) {
                    tmp_word_map[cur_word] += 1;
                } else {
                    tmp_word_map[cur_word] = 1;
                }
            }
            // judge valid
            if (is_map_equal(word_map, tmp_word_map)) {
                res.push_back(i);
            }
        }
        return res;
    }

private:
    void get_word_cnt_map(const vector<string>& words, unordered_map<string, int> &word_map) {
        for (const auto& word : words) {
            if (word_map.count(word) > 0) {
                word_map[word] += 1;
            } else {
                word_map[word] = 1;
            }
        }
    }

    bool is_map_equal(const unordered_map<string, int> &target,
                      const unordered_map<string, int> &ours) {
        for (auto& [word, cnt] : target) {
            auto it = ours.find(word);
            if (it == ours.end() || it->second != cnt) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution2 obj;

    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo","bar"};
    auto res1 = obj.findSubstring(s1, words1);
    print_vector(res1);

    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word","good","best","word"};
    auto res2 = obj.findSubstring(s2, words2);
    print_vector(res2);

    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar","foo","the"};
    auto res3 = obj.findSubstring(s3, words3);
    print_vector(res3);

    vector<string> words4 = {"word","good","best","good"};
    auto res4 = obj.findSubstring(s2, words4);
    print_vector(res4);

    string s5 = "foobarfoobar";
    auto res5 = obj.findSubstring(s5, words1);
    print_vector(res5);

    string s6 = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    vector<string> words6 = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
    auto res6 = obj.findSubstring(s6, words6);
    print_vector(res6);

    return 0;
}
