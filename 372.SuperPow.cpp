/*
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
Input: a = 2, b = [3]
Output: 8

Example 2:
Input: a = 2, b = [1,0]
Output: 1024
*/


class Solution {
public:
    // a^1564 = a^4 * a^1560
    //        = a^4 * (a^156)^10
    //           ⬆      ⬆
    //         left   right
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        int tail = b.back();
        b.pop_back();

        auto left = pow_helper(a, tail);
        auto right = pow_helper(superPow(a, b), 10); // 防止溢出
        return (left * right) % base;
    }

private:
    /**
      (a * b) % k = ((a % k) * (b % k)) % k
    provement:
        suppose: a = Ak + B;  b = Ck + D
        then: a * b = (Ak + B) * (Ck + D) = AC * (k^2) + (AD + BC) * k + BD
        then: (a * b) % k = BD % k

        and: a % k = (Ak + B) % k = B % k = B
             b % k = (Ck + D) % k = D % k = D
        so: (a % k) * (b % k) % k = BD % k
    */
    int pow_helper(int a, int k) {
        // 计算a^k, 注意有可能溢出
        a %= base;  // a可能比base大很多，提前求模有助于降低开销
        int result = 1;
        for (auto i = 0; i < k; ++i) {
            result *= a;
            result %= base;
        }
        return result;
    }

private:
    const int base = 1337;
};
