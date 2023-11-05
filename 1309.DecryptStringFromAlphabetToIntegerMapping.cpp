/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"
Example 3:

Input: s = "25#"
Output: "y"
Example 4:

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
 

Constraints:

1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
*/

class Solution {
public:
    string freqAlphabets(string s) {
        std::string result;
        
        auto pos = s.find_first_of('#');
        for (auto i = 0; i < s.size(); ) {
            if (pos == std::string::npos
                    || (pos != std::string::npos && i < pos - 2)) {
                result += static_cast<char>('a' + static_cast<int>(s[i] - '1'));
                ++i;
            } else {
                result += static_cast<char>('a' + std::stoi(s.substr(i, 2)) - 1);
                
                i += 3;
                pos = s.find_first_of('#', i);
            }
        }
        return result;
    }
};