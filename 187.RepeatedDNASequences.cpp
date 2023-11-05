/*
187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
    Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
    Return: ["AAAAACCCCC", "CCCCCAAAAA"].

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string &s) {
        vector<string> result;
        if (s.size() < 10) return result;

        unordered_map<string, int> uset;
        for (auto i = 0; i+9 < s.size(); ++i)
        {
            string tmp = s.substr(i, 10);
            if (uset.find(tmp) != uset.end()) ++uset[tmp];
            else uset[tmp] = 1;
        }
        for (auto &x : uset)
        {
            if (x.second > 1)
                result.push_back(x.first);
        }
        return result;
    }
};