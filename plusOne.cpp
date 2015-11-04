/*
66. Plus One
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

#include <vector>
#include <iostream>

vector<int> plusOne(vector<int> &digits)
{
    if (digits.size() == 0)
        return digits;

    int carry = 1;
    vector<int> res;
    while (digits.size())
    {
        int x = digits.back();
        x += carry;
        res.insert(res.begin(), x % 10);
        carry = x / 10;
        digits.pop_back();
    }
    if (carry)
        res.insert(res.begin(), carry);
    return res;
}

void testCase_plusOne()
{
    int s2[7] = {1, 2, 3, 4, 9, 8, 9};
    vector<int> s1(&s2[0], &s2[0] + sizeof(s2)/sizeof(int));
    vector<int> res;

    res = plusOne(s1);

    for (int i = 0; i < res.size(); i++)
        std::cout<<res[i]<<'\t';
}
