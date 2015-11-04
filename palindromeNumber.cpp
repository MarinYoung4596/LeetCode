/*
9. Palindrome Number
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
 * you know that the reversed integer might overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// First Solution, Space Complexity: O(N)
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    vector<int> bit;
    while (x)
    {
        bit.push_back(x % 10);
        x /= 10;
    }
    while(bit.size() > 1)
    {
        if (bit.front() != bit.back())
            return false;
        // if they are equal
        bit.pop_back();
        reverse(bit.begin(), bit.end());
        bit.pop_back();
    }
    return true;
}

// Second Solution, recursion, no extra space
bool isPalindrome(int x, int HIGH, int LOW)
{
	if (x < 0)
		return false;
	if (x < 10)
		return true;
	if (x < 100)
	    return (x / 10 == x % 10) ? true : false;

	while (x < HIGH)			// at the very begining
		HIGH /= 10;

	int highestBit = x / HIGH;	// 154670892 / 10000000 = 15
	highestBit %= 10;			// 15 % 10 = 5


	int lowestBit = x % LOW;	// 154670892 % 100 = 92
	lowestBit /= (LOW / 10);	// 92 / (100 / 10) = 9


	if (highestBit != lowestBit)
		return false;
	if (HIGH == LOW || LOW == HIGH * 10)
		return true;
	else
		return isPalindrome(x, HIGH / 10, LOW * 10);
}


bool isPalindrome_2(int x)
{
    int HIGH = 1000000000;
    int LOW = 10;
    return isPalindrome(x, HIGH, LOW);
}

void testCase_palindromeNumber()
{
    cout << "123454321:\t" << isPalindrome(123454321) << endl;
	cout << "1111021111:\t" << isPalindrome(1234024321) << endl;
	cout << "111211:\t" << isPalindrome(111211) << endl;
	cout << "111111111:\t" << isPalindrome(111111111) << endl;
	cout << "1876106781:\t" << isPalindrome(1876106781) << endl;
	cout << "11:\t" << isPalindrome(11) << endl;
	cout << "121:\t" << isPalindrome(121) << endl;
}

int main()
{
	testCase_palindromeNumber();
	
	return 0;
}

