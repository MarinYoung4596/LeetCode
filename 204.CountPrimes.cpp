/*
Description: Count the number of prime numbers less than a non-negative number, n
Hint: The number n could be in the order of 100,000 to 5,000,000.
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cmath>

using namespace std;

// see: http://www.zhihu.com/question/29580448
// https://en.wikipedia.org/wiki/Prime-counting_function#Algorithms_for_evaluating_.CF.80.28x.29
// https://primes.utm.edu/howmany.html


// First Solution: violent solution
// O(NlogN)    Time Limit Exceeded
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> prime;

        for (size_t i = 2; i * i <= n; i++) {
            if (!isPrime(i, prime)) {
                continue;
            }
            prime.push_back(i);
            count++;
        }
        return count;
    }

private:
    bool isPrime(int n, vector<int> prime) {
        for (int i = 0; i < prime.size(); ++i) {
            if (n % prime[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

// Second Solution:
// http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// passed in Visual Studio 2013
// Wrong answer in G++ 4.6.3
class Solution2 {
public:
    int countPrimes(int n) {
        vector<bool> seive(n + 1, true);
        for (int i = 2; i <= sqrt(n); ++i) {
            if (seive[i]) { // 相当于i的倍数，不可能是素数；
                for (int j = i * i; j <= n; j += i) { // j 从i*i 开始，因为i的整数倍都已经被标记
                    seive[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)    { // less than n
            if (seive[i]) {
                count++;
            }
        }
        return count;
    }
};


// Third Solution:
// http://www.zhihu.com/question/29580448/answer/45235320
// Correct in G++ 4.6.3
// Wrong answer in Visual Studio 2013
class Solution3 {
public:
    int countPrimes(int n) {
        vector<bool> seive(n + 1, false);
        vector<int> prime;

        for (int i = 2; i <= n; i++) {
            if (!seive[i]) {
                prime.push_back(i);
            }
            for (int j = 0; j < prime.size() && i * prime[j] < n; j++) {
                seive[i * prime[j]] = true;    // delete all the multiple number of both i and prime
                if (i % prime[j] == 0) break;
            }
        }
        return prime.size();
    }
};
