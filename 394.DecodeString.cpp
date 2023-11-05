/*
394. Decode String

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is
being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are
well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are
only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

private:
    static bool is_digit(char c) { return '0' <= c && c <= '9'; }

    string decode(string &s, int &i) {
        string result = "";
        for (; i < s.size() && s[i] != ']'; ++i) { // 到右括号截止
            if (!is_digit(s[i])) {
                result += s[i];
            } else { // digit
                int k = 0;
                for (; i < s.size() && is_digit(s[i]); ++i) {
                    k = k * 10 + static_cast<int>(s[i] - '0');
                }

                ++i;                       // 跳过 '['
                string tmp = decode(s, i); // 递归
                while (k--) {
                    result += tmp;
                }
            }
        }
        return result;
    }
};