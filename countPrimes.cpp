/*
204. Count Primes.
Description:

Count the number of prime numbers less than a non-negative number, n

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
// O(NlogN)	Time Limit Exceeded
bool isPrime(int n, vector<int> prime)
{
	for (int i = 0; i < prime.size(); ++i)
	{
		if (n % prime[i] == 0)
			return false;
	}
	return true;
}

int countPrimes(int n)
{
	int count = 0;
	vector<int> prime;

	for (size_t i = 2; i <= n; i++)
	{
		if (!isPrime(i, prime))
			continue;
		prime.push_back(i);
		count++;
	}
	return count;
}


// Second Solution: 
// http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// passed in Visual Studio 2013
// Wrong answer in G++ 4.6.3
int countPrimes_2(int n)
{
	bool *seive = new bool[n + 1];
	memset(seive, true, sizeof(seive));

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (seive[i])
		{
			for (int j = i * i; j <= n; j += i)
				seive[j] = false;
		}
	}

	int count = 0;
	for (int i = 2; i < n; i++)	// less than n
	{
		if (seive[i])
			count++;
	}
	return count;
}


// Third Solution:
// http://www.zhihu.com/question/29580448/answer/45235320
// Correct in G++ 4.6.3
// Wrong answer in Visual Studio 2013
int countPrimes_3(int n)
{
	bool *seive = new bool[n + 1];
	memset(seive, false, sizeof(seive));
	vector<int> prime;

	for (int i = 2; i <= n; i++)
	{
		if (!seive[i])
			prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < n; j++)
		{
			seive[i * prime[j]] = true;	// delete all the multiple number of both i and prime
			if (i % prime[j] == 0) break;
		}
	}
	return prime.size();
}


int main(int argc, char **argv)
{
	// test Case
	// OS:			Windows 8.1 Pro
	// Processor:	Intel(R) Core(TM) i5-2410M CPU (C) 2.30 GHz
	// Memory:		4.00 GB
	//	NUMBER		RUN TIME(s)
	//			1			2			3
	//	499979	123.816		0.008	
	//	1500000	812.517		0.024
	//	999983	397.336		0.017
	clock_t begin = clock();

	cout << countPrimes_3(999983) << endl;

	clock_t end = clock();
	double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
	std::cout << elapsed_secs << " s" << std::endl;

	system("pause");
	return 0;
}
