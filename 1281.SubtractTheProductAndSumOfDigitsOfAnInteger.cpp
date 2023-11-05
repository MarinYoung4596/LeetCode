/*

Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15


Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
 

Constraints:

1 <= n <= 10^5

*/
class Solution {
public:
    int subtractProductAndSum(int n) {
        std::vector<int> digits;
        get_all_digits(n, digits);
        
        int sum = std::accumulate(digits.begin(), digits.end(), 0, 
                       [](int x, int y) {
                           return x + y;
                       });
        int product = std::accumulate(digits.begin(), digits.end(), 1,
                       [](int x, int y) {
                          return x * y; 
                       });
        return product - sum;
    }
    
    void get_all_digits(int n, std::vector<int> &vec) {
        while (n > 0) {
            int d = n % 10;
            vec.push_back(d);
            n /= 10;
        }
    }
};