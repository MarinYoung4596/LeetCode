/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> vec;
        split(s, ' ', vec);
        std::string result;
        for (auto &item : vec) {
            reverse(item);
            result += item + ' ';
        }
        result.pop_back();
        return result;
    }

private:
    void split(const std::string &str, char sep, std::vector<std::string> &result) {
        int begin = 0;
        int end = str.find_first_of(sep, begin);
        while (end != std::string::npos) {
            result.push_back(str.substr(begin, end - begin));

            begin = str.find_first_not_of(sep, end);
            end = str.find_first_of(sep, begin);
        }
        if (begin != end) {
            result.push_back(str.substr(begin, str.size() - begin));
        }
    }

    void reverse(std::string &str) {
        int begin = 0;
        int end = str.size() - 1;
        while (begin < end) {
            std::swap(str[begin++], str[end--]);
        }
    }
};