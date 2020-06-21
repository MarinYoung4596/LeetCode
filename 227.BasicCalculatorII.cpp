/*
227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

*/


// Solution using one stack, 26ms
class Solution
{
public:
	int calculate(string s)
	{
		stack<int> digits;
		char sign = '+';
		int tmp = 0;
		for (auto i = 0; i < s.size(); ++i)
		{
			if (isdigit(s[i]))
			{
				tmp = tmp * 10 + static_cast<int>(s[i] - '0');
			}
			if ((!isdigit(s[i]) && !isspace(s[i])) ||
			    i == s.size() - 1)// 符号： + - * /
			{
				if (sign == '+' || sign == '-') 
				{
					digits.push((sign == '+' ? tmp : -tmp));
				}
				else
				{
					int prev = digits.top();
					digits.pop();
					if (sign == '*') digits.push(prev * tmp);
					else digits.push(prev / tmp);
				}
				tmp = 0;
				sign = s[i]; // current sign
			}
		}
		int result = 0;
		while (!digits.empty())
		{
			result += digits.top();
			digits.pop();
		}
		return result;
	}
};


// Second solution : using two stacks, 42ms
class Solution2
{
public:
	int calculate(string s)
	{
		for (auto i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')   continue;
			if (isdigit(s[i]))
			{
				if (i != 0 && isdigit(s[i-1]))
				{
					int tmp = digits.top() * 10 + static_cast<int>(s[i] - '0');
					digits.pop();
					digits.push(tmp);
				}
				else
				{
					digits.push(static_cast<int>(s[i] - '0'));
				}
			}
			else
			{
				while (!operation.empty() && priority(operation.top()) >= priority(s[i]))
				{
					calculate_by_stack();
				}
				operation.push(s[i]);
			}
		}
		while (!operation.empty())
		{
			calculate_by_stack();
		}
		return digits.top();
	}

private:
	stack<int> digits;
	stack<char> operation;

	static int priority(char c)
	{
		return c == '+' || c == '-' ? 0 : 1;
	}
	static int calculate(char op, int lhs, int rhs)
	{
		switch(op)
		{
		case '+':
			return lhs + rhs;
		case '-':
			return lhs - rhs;
		case '*':
			return lhs * rhs;
		case '/':
			return lhs / rhs;
		default:
			return lhs;//ERROR
		}
	}
	void calculate_by_stack()
	{
		char op = operation.top();
		operation.pop();
		int curr = digits.top();
		digits.pop();
		int prev = digits.top();
		digits.pop();

		digits.push(calculate(op, prev, curr));
	}
};

