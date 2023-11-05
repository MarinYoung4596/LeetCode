/*
383. Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom  note can be constructed from the magazines ; otherwise, it will return false. 

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/

class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        int mag[26];
        memset(mag, 0, sizeof(mag));
        for (auto iter = magazine.begin(); iter != magazine.end(); ++iter)
        {
            int index = static_cast<int>(*iter - 'a');
            if (mag[index] != 0) ++mag[index];
            else mag[index] = 1;
        }
        for (auto iter = ransomNote.begin(); iter != ransomNote.end(); ++iter)
        {
            int index = static_cast<int>(*iter - 'a');
            if (mag[index] == 0) return false;
            --mag[index];
        }
        return true;
    }
};