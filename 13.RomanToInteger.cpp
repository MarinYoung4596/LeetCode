/*

13. Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    int romanToInt(string &s) {
        //'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000
        unordered_map<char, int> mapping;
        mapping.insert({'I',1});
        mapping.insert({'V',5});
        mapping.insert({'X',10});
        mapping.insert({'L',50});
        mapping.insert({'C',100});
        mapping.insert({'D',500});
        mapping.insert({'M',1000});
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char next = ((i + 1 == s.size()) ? 'I' : s[i+1]);
            if (mapping[s[i]] >= mapping[next]) res += mapping[s[i]];//右边，VII, XII, LI
            else res -= mapping[s[i]]; // 左边：IV, 
        }
        
        return res;
    }
};