/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
    Input: words = ["gin", "zen", "gig", "msg"]
    Output: 2
    Explanation: The transformation of each word is:
        "gin" -> "--...-."
        "zen" -> "--...-."
        "gig" -> "--...--."
        "msg" -> "--...--."
    There are 2 different transformations, "--...-." and "--...--.".


Note:
    The length of words will be at most 100.
    Each words[i] will have length in range [1, 12].
    words[i] will only consist of lowercase letters.

*/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::string arr[26] = {
            ".-","-...","-.-.","-..",".","..-.","--.",
            "....","..",".---","-.-",".-..","--","-.",
            "---",".--.","--.-", ".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."};

        std::unordered_set<std::string> str_set;
        for (auto it = words.begin(); it != words.end(); ++it) {
            std::string trans;
            for (auto jt = it->begin(); jt != it->end(); ++jt) {
                trans += arr[*jt - 'a'];
            }
            str_set.insert(trans);
        }
        return str_set.size();
    }
};