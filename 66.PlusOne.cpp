/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty()) {
            return digits;
        }

        int carry = 1;
        vector<int> res;
        while (digits.size()) {
            int x = digits.back();
            x += carry;
            res.insert(res.begin(), x % 10);
            carry = x / 10;
            digits.pop_back();
        }
        if (carry) {
            res.insert(res.begin(), carry);
        }
        return res;
    }
};
