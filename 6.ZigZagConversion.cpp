/*

6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

class Solution {
/*n=numRows
жд=2n-2    1                           2n-1                         4n-3
жд=        2                     2n-2  2n                    4n-4   4n-2
жд=        3               2n-3        2n+1              4n-5       .
жд=        .           .               .               .            .
жд=        .       n+2                 .           3n               .
жд=        n-1 n+1                     3n-3    3n-1                 5n-5
жд=2n-2    n                           3n-2                         5n-4
*/
public:
    string convert(string &s, int numRows) {
        if (s.size() <= numRows || numRows <= 1) 
            return s;
        string x[numRows];

        for (auto i = 0; i < s.size(); )
        {
            for (auto j = 0; j < numRows && i < s.size(); ++j)
            {
                x[j] += s[i++];
            }
            for (auto j = numRows-2; j > 0 && i < s.size(); --j)
            {
                x[j] += s[i++];
            }
        }
        string res ="";
        for (auto i = 0; i < numRows; ++i)
            res += x[i];
        return res;
    }
};