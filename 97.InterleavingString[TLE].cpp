/*

97. Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/
// Time Limit Exceeded
class Solution {
public:
    // ´ÓºóÍùÇ°
    bool isInterleave(string &s1, string &s2, string &s3) 
    {
        if (s3.size() != (s1.size() + s2.size())) return false;
        return dfs(s1, s1.size()-1, s2, s2.size()-1, s3, s3.size()-1);
    }
    
private:
    bool dfs(string &s1, int i, string &s2, int j, string &s3, int k)
    {
        if (k == -1) return true;
        if (i == -1) return s2[j] != s3[k] ? false : dfs(s1, -1, s2, j-1, s3, k-1);
        if (j == -1) return s1[i] != s3[k] ? false : dfs(s1, i-1, s2, -1, s3, k-1);
        
        if (s3[k] == s1[i] && s3[k] == s2[j]) return dfs(s1, i-1, s2, j, s3, k-1) || dfs(s1, i, s2, j-1, s3, k-1);
        if (s3[k] == s1[i]) return dfs(s1, i-1, s2, j, s3, k-1);// s3[k] != s2[j]
        if (s3[k] == s2[j]) return dfs(s1, i, s2, j-1, s3, k-1);// s3[k] != s1[i] 
        return false; // s3[k] != s1[i] && s3[k] != s2[j]
    }
};